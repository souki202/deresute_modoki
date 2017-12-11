#pragma once
#include <vector>
#include <array>
#include "NoteCommon.h"
#include "JudgeGrade.h"
#include "JudgeView.h"
#include "InputDevice.h"
#include "JudgeResult.h"

class Judge {
public:
	Judge() { setJudgeDifficulty(1); };
	~Judge() {};

	void setJudgeDifficulty(int difficulty);
	void resetJudgedId() { judgedId.clear(); };
	JudgeResult judge(const JudgeTiming& timing, int nowTime, int judgeTime, int line, int touchId);
	JudgeGrade calcGrade(int deltaTime, bool isInLn = false);
	JudgeGrade calcFlickGrade(int deltaTime);

	int searchUnuseId(const InputDevice::TouchMap& touches, int line); //処理済みか中身なしなら-1

	void update() { view.update(); };
	void draw() { view.draw(); };
private:
	JudgeView view;
	std::vector<int> judgedId;//判定済みのidを格納
	std::array<int, static_cast<int>(JudgeGrade::INVALID)> judgeRange;
	std::array<int, static_cast<int>(JudgeGrade::INVALID)> flickJudgeRange;
};