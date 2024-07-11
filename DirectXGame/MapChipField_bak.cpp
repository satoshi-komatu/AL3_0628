#include <cassert>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>

namespace {
std::map<std::string, MapChipType> mapChipTable = {
    {"0", MapChipType::kBlank},
    {"1", MapChipType::kBlock},
};
}

void MapChipField::ResetMapChipData() {
    //マップチップのデータリセット
	mapChipData_.deta.clear();
	mapChipData_.deta.resize(kNumBlockVirtical);
	for (std::vector<MapChipType>& mapChipDataLine : mapChipData_.deta) {
	
		 mapChipDataLine.resize(kNumBlockHorizontal);
	}
}

void MapChipField::LoadMapChipCsv(const std::string& filePath) { 
	std::ifstream file;
	file.open(filePath);
	assert(file.is_open());

	std::stringstream mapChipCsv;

	mapChipCsv << file.rdbuf();

	file.close();

	ResetMapChipData();

	std::string line;

	for (uint32_t i = 0; i < kNumBlockVirtical; ++i) {
		getline(mapChipCsv, line);

		std::istringstream line_stream(line);

		for (uint32_t j = 0; j < kNumBlockHorizontal; ++j) {
			std::string word;
			getline(line_stream, word, ',');

			if (mapChipTable.contains(word)) {
				mapChipData_.deta[i][j] = mapChipTable[word];
			}
		}
	}
}

Vector3 MapChipField::GetMapChipPositionByIndex(uint32_t xindex, uint32_t yindex) { return Vector3(kBlockWidth * xindex,kBlockHeight *(kNumBlockVirtical - 1- yindex),0); }

MapChipType MapChipField::GetMapChipTypeByIndex(uint32_t xindex, uint32_t yindex) {
	if (xindex < 0 || kNumBlockHorizontal - 1 < xindex) {
		return MapChipType::kBlank;
	}
	if (yindex < 0 || kNumBlockVirtical - 1 < yindex) {
		return MapChipType::kBlank;
	}

	return mapChipData_.deta[yindex][xindex];
}
