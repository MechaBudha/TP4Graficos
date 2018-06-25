#include "MugettiSimpleScoreLib.h"



MugettiSimpleScoreLib::MugettiSimpleScoreLib()
{
	for (int i = 0; i < BOARDTAM; i++) {
		_ScoreTable[i].sco = 0;
		for (int j = 0; j < NOMTAM; j++) {
			_ScoreTable[i].nom[j] = ' ';
		}
	}
}

bool MugettiSimpleScoreLib::RecordCurrentScore(int score, char name[NOMTAM]) {
	Score actual;
	actual.sco = score;
	for (int i = 0; i < NOMTAM; i++){
		actual.nom[i] = name[i];
	}

	return Sort(actual);


}
void MugettiSimpleScoreLib::GetMaxScore(int& score, char* name[NOMTAM]) {
	Score _MaxScore = _ScoreTable[0];
	score = _MaxScore.sco;
	for (int i = 0; i < NOMTAM; i++) {
		*name[i] = _MaxScore.nom[i];
	}
}

bool MugettiSimpleScoreLib::Sort(Score actual) {
	for (int i = 0; i < BOARDTAM; i++){
		if (actual.sco > _ScoreTable[i].sco){
			int tam = BOARDTAM - i;
			for (int j = 0; j < tam; j++){
				_ScoreTable[i + tam - j].sco = _ScoreTable[i +1 +tam -(j+1)].sco;
				for (int k = 0; k < NOMTAM; k++){
					_ScoreTable[i + tam - j].nom[k] = _ScoreTable[i + 1 + tam - (j + 1)].nom[k];
				}

			}
			return true;
		}
	}
	return false;
}

bool MugettiSimpleScoreLib::GetPlayerPositionByScore(int score, int& position) {
	for (int i = 0; i < BOARDTAM; i++){
		if (_ScoreTable[i].sco == score) {
			position = i + 1;
			return true;
		}
	}
	return false;
}

bool MugettiSimpleScoreLib::GetPlayerPositionByName(char name[NOMTAM], int& position) {
	for (int i = 0; i < BOARDTAM; i++){
		bool found = true;

		for (int j = 0; j < NOMTAM; j++){
			if (name[j] != _ScoreTable[i].nom[j]){
				found = false;
			}
		}

		if (found){
			position = i + 1;
			return true;
		}
	}
	return false;
}

bool MugettiSimpleScoreLib::GetPositionScore(int position, int&score, char* name[NOMTAM]) {
	if (position >= 1 && position<=BOARDTAM){
		score = _ScoreTable[position].sco;
		for (int i = 0; i < NOMTAM; i++){
			*name[i] = _ScoreTable[position].nom[i];
		}
		return true;
	}else{return false;}
}

MugettiSimpleScoreLib::~MugettiSimpleScoreLib()
{
}
