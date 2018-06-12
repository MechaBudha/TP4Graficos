#include "MugettiSimpleScoreLib.h"



MugettiSimpleScoreLib::MugettiSimpleScoreLib()
{
}
void MugettiSimpleScoreLib::Init() {
	_MaxScore.sco = 0;
	_CurScore.sco = 0;
	for (int i = 0; i < NOMTAM; i++) {
		_MaxScore.nom[i] = ' ';
		_CurScore.nom[i] = ' ';
	}
}
bool MugettiSimpleScoreLib::RecordScore(int score, char name[NOMTAM]) {
	_CurScore.sco = score;
	for (int i = 0; i < NOMTAM; i++) {
		_CurScore.nom[i] = name[i];
	}

	if (_CurScore.sco > _MaxScore.sco) {
		_MaxScore.sco = _CurScore.sco;
		for (int i = 0; i < NOMTAM; i++) {
			_MaxScore.nom[i] = _CurScore.nom[i];
		}
		return true;
	}
	else { return false; }
}
void MugettiSimpleScoreLib::GetMaxScore(int& score, char* name[NOMTAM]) {
	score = _MaxScore.sco;
	for (int i = 0; i < NOMTAM; i++) {
		*name[i] = _MaxScore.nom[i];
	}
}

void MugettiSimpleScoreLib::GetCurrentScore(int& score, char* name[NOMTAM]) {
	score = _CurScore.sco;
	for (int i = 0; i < NOMTAM; i++) {
		*name[i] = _CurScore.nom[i];
	}
}

MugettiSimpleScoreLib::~MugettiSimpleScoreLib()
{
}
