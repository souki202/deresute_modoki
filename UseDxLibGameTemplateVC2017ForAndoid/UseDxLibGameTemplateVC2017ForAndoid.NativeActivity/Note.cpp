#include "Note.h"

void Note::update()
{
	//座標計算
	int viewTime = playSettings.getViewNoteTime();
	//x座標
	int appearX = playPositions.getCenterPosition(appearPos);
	int targetX = playPositions.getCenterPosition(target);
}

void Note::setting(int target, float appear, int judgeTime, int uid, int id)
{
	this->target = target;
	this->appearPos = appear;
	this->judgeTime = judgeTime;
	this->id = id;
	this->uid = uid;
}
