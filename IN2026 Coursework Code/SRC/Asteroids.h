#ifndef __ASTEROIDS_H__
#define __ASTEROIDS_H__

#include "GameUtil.h"
#include "GameSession.h"
#include "IKeyboardListener.h"
#include "IGameWorldListener.h"
#include "IScoreListener.h" 
#include "ScoreKeeper.h"
#include "Player.h"
#include "IPlayerListener.h"
#include <map>
#include "Spaceship.h"
#include "DemoSpaceship.h"
#include <vector>
#include <memory>



class GameObject;
class Spaceship;
class GUILabel;

class Asteroids : public GameSession, public IKeyboardListener, public IGameWorldListener, public IScoreListener, public IPlayerListener
{
public:
	Asteroids(int argc, char *argv[]);
	virtual ~Asteroids(void);

	virtual void Start(void);
	virtual void Stop(void);

	// Declaration of IKeyboardListener interface ////////////////////////////////

	void OnKeyPressed(uchar key, int x, int y);
	void OnKeyReleased(uchar key, int x, int y);
	void OnSpecialKeyPressed(int key, int x, int y);
	void OnSpecialKeyReleased(int key, int x, int y);

	// Declaration of IScoreListener interface //////////////////////////////////

	void OnScoreChanged(int score);


	

	// Declaration of the IPlayerLister interface //////////////////////////////

	void OnPlayerKilled(int lives_left);

	// Declaration of IGameWorldListener interface //////////////////////////////

	void OnWorldUpdated(GameWorld* world) {}
	void OnObjectAdded(GameWorld* world, shared_ptr<GameObject> object) {}
	void OnObjectRemoved(GameWorld* world, shared_ptr<GameObject> object);

	// Override the default implementation of ITimerListener ////////////////////
	void OnTimer(int value);

	void setAsteroidCount(int s) {
		asteroidCount = s;
	}
	
private:
	shared_ptr<Spaceship> mSpaceship;

	shared_ptr<DemoSpaceship> mDemoSpaceship;


	shared_ptr<GUILabel> mScoreLabel;
	shared_ptr<GUILabel> mLivesLabel;
	shared_ptr<GUILabel> mGameOverLabel;
	shared_ptr<GUILabel> mStartGame;
	shared_ptr<GUILabel> mExitGame;
	shared_ptr<GUILabel> mEnterName;

	//High Score Table Labels
	shared_ptr<GUILabel> mHighScoreTable;
	shared_ptr<GUILabel> mPrintScore;
	shared_ptr<GUILabel> mPrintName;
	shared_ptr<GUILabel> mTShowName;
	shared_ptr<GUILabel> mName;

	vector<shared_ptr<GameObject>> AsteroidPosTraker;

	uint mLevel;
	uint mAsteroidCount;

	int asteroidCount = 10;

	bool gameStatus = false;

	//if true will allow the player to enter name
	bool enterName = false;

	bool scoretable = true;

	bool gamecheck = true;

	//holds players name
	string name;

	//count typing letters
	int count = 0;

	void ResetSpaceship();
	shared_ptr<GameObject> CreateSpaceship();
	shared_ptr<GameObject> CreateDemoSpaceship();
	void CreateAsteroids(const uint num_asteroids);
	void CreateGUI();
	void CreateStartScreenGUI();
	void CreateNameGUI();
	void RemoveHighScoreIntrustionGUI();
	void RemoveStartScreenGUI();
	//void CreateAsteroids(const uint num_asteroids);

	
	shared_ptr<GameObject> CreateExplosion();

	//keep the players name and their score
	map<int,string > playerRecords;

	//writes the players name and their score to the file
	void WriteScore();
	
	//reads the players name and add it to the score.
	void ReadScore();
	
	
	const static uint SHOW_GAME_OVER = 0;
	const static uint START_NEXT_LEVEL = 1;
	const static uint CREATE_NEW_PLAYER = 2;

	const static uint SHOW_HIGH_SCORE_TABLE = 3;

	const static uint START_DEMO_MODE = 4;

	const static uint RESET_DEMO_SPACESHIP = 5;

	ScoreKeeper mScoreKeeper;
	Player mPlayer;
};

#endif