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
	Score _MaxScore;
	Score _CurScore;
public:
	MugettiSimpleScoreLib();
	void Init();
	bool RecordScore(int score, char name[NOMTAM]);
	void GetMaxScore(int& score, char* name[NOMTAM]);
	void GetCurrentScore(int& score, char* name[NOMTAM]);
	~MugettiSimpleScoreLib();
};
#endif // !SCORELIB_H

