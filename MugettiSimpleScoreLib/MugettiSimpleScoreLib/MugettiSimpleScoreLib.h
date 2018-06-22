#ifndef SCORELIB_H
#define SCORELIB_H
#define NOMTAM 3
#define BOARDTAM 10


struct Score
{
	int sco;
	char nom[NOMTAM];
};
class MugettiSimpleScoreLib
{
	Score _ScoreTable[BOARDTAM];

	bool Sort(Score actual);
public:
	MugettiSimpleScoreLib();
	bool RecordCurrentScore(int score, char name[NOMTAM]);
	void GetMaxScore(int& score, char* name[NOMTAM]);
	bool GetPlayerPositionByScore(int score, int& position);
	bool GetPlayerPositionByName(char name[NOMTAM], int& position);
	bool GetPositionScore(int position, int&score, char* name[NOMTAM]);
	int GetScoreBoardSize() { return BOARDTAM; }
	~MugettiSimpleScoreLib();
};
#endif // !SCORELIB_H

