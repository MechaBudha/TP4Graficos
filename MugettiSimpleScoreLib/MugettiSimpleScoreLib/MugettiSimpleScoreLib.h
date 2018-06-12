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
	Score _CurScore;
	Score _ScoreTable[BOARDTAM];

	void Sort();
public:
	MugettiSimpleScoreLib();
	void Init();
	bool RecordCurrentScore(int score, char name[NOMTAM]);
	void GetMaxScore(int& score, char* name[NOMTAM]);
	void GetCurrentScore(int& score, char* name[NOMTAM]);
	int GetPlayerPositionByScore();
	int GetPlayerPositionByName();
	Bool GetPositionScore();
	int GetMinPosition() { return BOARDTAM; };
	int GetMaxPosition() { return 1; };
	~MugettiSimpleScoreLib();
};
#endif // !SCORELIB_H

