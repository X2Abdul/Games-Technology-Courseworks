#include "Asteroid.h"
#include "Asteroids.h"
#include "Animation.h"
#include "AnimationManager.h"
#include "GameUtil.h"
#include "GameWindow.h"
#include "GameWorld.h"
#include "GameDisplay.h"
#include "Spaceship.h"
#include "BoundingShape.h"
#include "BoundingSphere.h"
#include "GUILabel.h"
#include "Explosion.h"
#include "ScoreKeeper.h"
#include <vector>
#include <algorithm>
#include <fstream>
// PUBLIC INSTANCE CONSTRUCTORS ///////////////////////////////////////////////

/** Constructor. Takes arguments from command line, just in case. */
Asteroids::Asteroids(int argc, char *argv[])
	: GameSession(argc, argv)
{
	mLevel = 0;
	mAsteroidCount = 0;
}

/** Destructor. */
Asteroids::~Asteroids(void)
{
}

// PUBLIC INSTANCE METHODS ////////////////////////////////////////////////////

/** Start an asteroids game. */
void Asteroids::Start()
{
	
	// Create a shared pointer for the Asteroids game object - DO NOT REMOVE
	shared_ptr<Asteroids> thisPtr = shared_ptr<Asteroids>(this);

	// Add this class as a listener of the game world
	mGameWorld->AddListener(thisPtr.get());

	// Add this as a listener to the world and the keyboard
	mGameWindow->AddKeyboardListener(thisPtr);

	// Add a score keeper to the game world
	mGameWorld->AddListener(&mScoreKeeper);

	// Add this class as a listener of the score keeper
	mScoreKeeper.AddListener(thisPtr);

	// Create an ambient light to show sprite textures
	GLfloat ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat diffuse_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
	glEnable(GL_LIGHT0);

	Animation *explosion_anim = AnimationManager::GetInstance().CreateAnimationFromFile("explosion", 64, 1024, 64, 64, "explosion_fs.png");
	Animation *asteroid1_anim = AnimationManager::GetInstance().CreateAnimationFromFile("asteroid1", 128, 8192, 128, 128, "asteroid1_fs.png");
	Animation *spaceship_anim = AnimationManager::GetInstance().CreateAnimationFromFile("spaceship", 128, 128, 128, 128, "spaceship_fs.png");

	// Add a player (watcher) to the game world
	mGameWorld->AddListener(&mPlayer);

	// Add this class as a listener of the player
	mPlayer.AddListener(thisPtr);

	// Creates a start screen gui which displays option to start and exit the game
	CreateStartScreenGUI();

	// Start the game
	GameSession::Start();
}

/** Stop the current game. */
void Asteroids::Stop()
{
	// Stop the game
	GameSession::Stop();
	
}

// PUBLIC INSTANCE METHODS IMPLEMENTING IKeyboardListener /////////////////////

void Asteroids::OnKeyPressed(uchar key, int x, int y)
{
	switch (key)
	{
	case ' ':
		mSpaceship->Shoot();
		break;

	//all the cases below will add whichever leter is pressed to a string to hold players name.
	case 'a':
		if (enterName) {
			
			name += "a";
			if (count > 0) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'b':
		if (enterName) {
			
			name += "b";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'c':
		if (enterName) {
			
			name += "c";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'd':
		if (enterName) {
			;
			name += "d";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'e':
		if (enterName) {
			
			name += "e";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'f':
		if (enterName) {
			
			name += "f";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'g':
		if (enterName) {
			name += "g";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'h':
		if (enterName) {
			name += "h";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'i':
		if (enterName) {
			name += "i";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'j':
		if (enterName) {
			name += "j";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'k':
		if (enterName) {
			name += "k";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'l':
		if (enterName) {
			name += "l";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;
		
	case 'm':
		if (enterName) {
			name += "m";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'n':
		if (enterName) {
			name += "n";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'o':
		if (enterName) {
			name += "o";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'p':
		if (enterName) {
			name += "p";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'q':
		if (enterName) {
			name += "q";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'r':
		if (enterName) {
			name += "r";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 's':
		if (enterName) {
			name += "s";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 't':
		if (enterName) {
			name += "t";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'u':
		if (enterName) {
			name += "u";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'v':
		if (enterName) {
			name += "v";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;
#
	case 'w':
		if (enterName) {
			name += "w";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'x':
		if (enterName) {
			name += "x";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'y':
		if (enterName) {
			name += "y";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;

	case 'z':
		if (enterName) {
			name += "z";
			if (name.size() > 1) {
				mTShowName->SetVisible(false);
			}
			CreateNameGUI();
		}
		break;


	//stop player from typing their name
	case '1':
		enterName = false;
		SetTimer(500, SHOW_HIGH_SCORE_TABLE);
		break;
	default:
		break;
	}
}

void Asteroids::OnKeyReleased(uchar key, int x, int y) {}

void Asteroids::OnSpecialKeyPressed(int key, int x, int y)
{
	switch (key)
	{
	// If up arrow key is pressed start applying forward thrust
	case GLUT_KEY_UP: mSpaceship->Thrust(10); break;
	// If left arrow key is pressed start rotating anti-clockwise
	case GLUT_KEY_LEFT: mSpaceship->Rotate(90); break;
	// If right arrow key is pressed start rotating clockwise
	case GLUT_KEY_RIGHT: mSpaceship->Rotate(-90); break;
	// Default case - do nothing
	case GLUT_KEY_DOWN:
		
		if (!spaceshipAlive) {
			// Create a spaceship and add it to the world
			mGameWorld->AddObject(CreateSpaceship());
			// Create some asteroids and add them to the world
			CreateAsteroids(10);
			//removes start screen gui
			RemoveStartScreenGUI();
			//Create the GUI
			CreateGUI();
			//set the game start bool to true
			spaceshipAlive = true;
			break;
		}

		break;

	case GLUT_KEY_END:
		Stop();
		break;
	default: break;
	}
}



void Asteroids::OnSpecialKeyReleased(int key, int x, int y)
{
	switch (key)
	{
	// If up arrow key is released stop applying forward thrust
	case GLUT_KEY_UP: mSpaceship->Thrust(0); break;
	// If left arrow key is released stop rotating
	case GLUT_KEY_LEFT: mSpaceship->Rotate(0); break;
	// If right arrow key is released stop rotating
	case GLUT_KEY_RIGHT: mSpaceship->Rotate(0); break;
	// Default case - do nothing
	default: break;
	} 
}


// PUBLIC INSTANCE METHODS IMPLEMENTING IGameWorldListener ////////////////////

void Asteroids::OnObjectRemoved(GameWorld* world, shared_ptr<GameObject> object)
{
	if (object->GetType() == GameObjectType("Asteroid"))
	{
		shared_ptr<GameObject> explosion = CreateExplosion();
		explosion->SetPosition(object->GetPosition());
		explosion->SetRotation(object->GetRotation());
		mGameWorld->AddObject(explosion);
		mAsteroidCount--;
		if (mAsteroidCount <= 0) 
		{ 
			SetTimer(500, START_NEXT_LEVEL); 
		}
	}
}

// PUBLIC INSTANCE METHODS IMPLEMENTING ITimerListener ////////////////////////

void Asteroids::OnTimer(int value)
{
	if (value == CREATE_NEW_PLAYER)
	{
		mSpaceship->Reset();
		mGameWorld->AddObject(mSpaceship);
	}

	if (value == START_NEXT_LEVEL)
	{
		mLevel++;
		int num_asteroids = 10 + 2 * mLevel;
		CreateAsteroids(num_asteroids);
	}

	if (value == SHOW_GAME_OVER)
	{
		
		spaceshipAlive = false;
		mGameOverLabel->SetVisible(true);
		mScoreLabel->SetVisible(false);
		mLivesLabel->SetVisible(false);
		mEnterName->SetVisible(true);
		mName->SetVisible(true);
		enterName = true;
		
	}

	if (value == SHOW_HIGH_SCORE_TABLE) {
		RemoveHighScoreIntrustionGUI();
		WriteScore();
		ReadScore();
		
	}

}

// PROTECTED INSTANCE METHODS /////////////////////////////////////////////////
shared_ptr<GameObject> Asteroids::CreateSpaceship()
{
	// Create a raw pointer to a spaceship that can be converted to
	// shared_ptrs of different types because GameWorld implements IRefCount
	mSpaceship = make_shared<Spaceship>();
	mSpaceship->SetBoundingShape(make_shared<BoundingSphere>(mSpaceship->GetThisPtr(), 4.0f));
	shared_ptr<Shape> bullet_shape = make_shared<Shape>("bullet.shape");
	mSpaceship->SetBulletShape(bullet_shape);
	Animation *anim_ptr = AnimationManager::GetInstance().GetAnimationByName("spaceship");
	shared_ptr<Sprite> spaceship_sprite =
		make_shared<Sprite>(anim_ptr->GetWidth(), anim_ptr->GetHeight(), anim_ptr);
	mSpaceship->SetSprite(spaceship_sprite);
	mSpaceship->SetScale(0.1f);
	// Reset spaceship back to centre of the world
	mSpaceship->Reset();
	// Return the spaceship so it can be added to the world
	return mSpaceship;

}

void Asteroids::CreateAsteroids(const uint num_asteroids)
{
	mAsteroidCount = num_asteroids;
	for (uint i = 0; i < num_asteroids; i++)
	{
		Animation *anim_ptr = AnimationManager::GetInstance().GetAnimationByName("asteroid1");
		shared_ptr<Sprite> asteroid_sprite
			= make_shared<Sprite>(anim_ptr->GetWidth(), anim_ptr->GetHeight(), anim_ptr);
		asteroid_sprite->SetLoopAnimation(true);
		shared_ptr<GameObject> asteroid = make_shared<Asteroid>();
		asteroid->SetBoundingShape(make_shared<BoundingSphere>(asteroid->GetThisPtr(), 10.0f));
		asteroid->SetSprite(asteroid_sprite);
		asteroid->SetScale(0.2f);
		mGameWorld->AddObject(asteroid);
	}
}

void Asteroids::CreateGUI()
{
	// Add a (transparent) border around the edge of the game display
	mGameDisplay->GetContainer()->SetBorder(GLVector2i(10, 10));
	// Create a new GUILabel and wrap it up in a shared_ptr
	mScoreLabel = make_shared<GUILabel>("Score: 0");
	// Set the vertical alignment of the label to GUI_VALIGN_TOP
	mScoreLabel->SetVerticalAlignment(GUIComponent::GUI_VALIGN_TOP);
	// Add the GUILabel to the GUIComponent  
	shared_ptr<GUIComponent> score_component
		= static_pointer_cast<GUIComponent>(mScoreLabel);
	mGameDisplay->GetContainer()->AddComponent(score_component, GLVector2f(0.0f, 1.0f));

	// Create a new GUILabel and wrap it up in a shared_ptr
	mLivesLabel = make_shared<GUILabel>("Lives: 3");
	// Set the vertical alignment of the label to GUI_VALIGN_BOTTOM
	mLivesLabel->SetVerticalAlignment(GUIComponent::GUI_VALIGN_BOTTOM);
	// Add the GUILabel to the GUIComponent  
	shared_ptr<GUIComponent> lives_component = static_pointer_cast<GUIComponent>(mLivesLabel);
	mGameDisplay->GetContainer()->AddComponent(lives_component, GLVector2f(0.0f, 0.0f));

	// Create a new GUILabel and wrap it up in a shared_ptr
	mGameOverLabel = shared_ptr<GUILabel>(new GUILabel("GAME OVER"));
	// Set the horizontal alignment of the label to GUI_HALIGN_CENTER
	mGameOverLabel->SetHorizontalAlignment(GUIComponent::GUI_HALIGN_CENTER);
	// Set the vertical alignment of the label to GUI_VALIGN_MIDDLE
	mGameOverLabel->SetVerticalAlignment(GUIComponent::GUI_VALIGN_MIDDLE);
	// Set the visibility of the label to false (hidden)
	mGameOverLabel->SetVisible(false);
	// Add the GUILabel to the GUIContainer  
	shared_ptr<GUIComponent> game_over_component
		= static_pointer_cast<GUIComponent>(mGameOverLabel);
	mGameDisplay->GetContainer()->AddComponent(game_over_component, GLVector2f(0.5f, 0.2f));

	
	// Create a new GUILabel and wrap it up in a shared_ptr
	mEnterName = shared_ptr<GUILabel>(new GUILabel("Please Type Your Name - Press 1 When Done"));
	// Set the horizontal alignment of the label to GUI_HALIGN_CENTER
	mEnterName->SetHorizontalAlignment(GUIComponent::GUI_HALIGN_CENTER);
	// Set the vertical alignment of the label to GUI_VALIGN_MIDDLE
	mEnterName->SetVerticalAlignment(GUIComponent::GUI_VALIGN_BOTTOM);
	// Set the visibility of the label to false (hidden)
	mEnterName->SetVisible(false);
	// Add the GUILabel to the GUIContainer  
	shared_ptr<GUIComponent> play_again_component
		= static_pointer_cast<GUIComponent>(mEnterName);
	mGameDisplay->GetContainer()->AddComponent(play_again_component, GLVector2f(0.5f, 0.1f));

	// Create a new GUILabel and wrap it up in a shared_ptr
	mName = shared_ptr<GUILabel>(new GUILabel("Name: "));
	// Set the horizontal alignment of the label to GUI_HALIGN_CENTER
	mName->SetHorizontalAlignment(GUIComponent::GUI_HALIGN_CENTER);
	// Set the vertical alignment of the label to GUI_VALIGN_MIDDLE
	mName->SetVerticalAlignment(GUIComponent::GUI_VALIGN_BOTTOM);
	// Set the visibility of the label to false (hidden)
	mName->SetVisible(false);
	// Add the GUILabel to the GUIContainer  
	shared_ptr<GUIComponent> name_component
		= static_pointer_cast<GUIComponent>(mName);
	mGameDisplay->GetContainer()->AddComponent(name_component, GLVector2f(0.3f, 0.5f));
	
}
void Asteroids::CreateStartScreenGUI() {
	// Create a new GUILabel and wrap it up in a shared_ptr
	mStartGame = make_shared<GUILabel>("Press \"DOWN ARROW KEY\" To Start");
	// Set the vertical alignment of the label to GUI_VALIGN_BOTTOM
	mStartGame->SetVerticalAlignment(GUIComponent::GUI_VALIGN_BOTTOM);
	// Add the GUILabel to the GUIComponent  
	shared_ptr<GUIComponent> start_game_component = static_pointer_cast<GUIComponent>(mStartGame);
	mGameDisplay->GetContainer()->AddComponent(start_game_component, GLVector2f(0.18f, 0.6f));

	// Create a new GUILabel and wrap it up in a shared_ptr
	mExitGame = make_shared<GUILabel>("Press \"End Key\" To Exit");
	// Set the vertical alignment of the label to GUI_VALIGN_BOTTOM
	mExitGame->SetVerticalAlignment(GUIComponent::GUI_VALIGN_BOTTOM);
	// Add the GUILabel to the GUIComponent  
	shared_ptr<GUIComponent> exit_game_component = static_pointer_cast<GUIComponent>(mExitGame);
	mGameDisplay->GetContainer()->AddComponent(exit_game_component, GLVector2f(0.25f, 0.2f));

}

void Asteroids::CreateNameGUI() {
	// Create a new GUILabel and wrap it up in a shared_ptr
	mTShowName = make_shared<GUILabel>(name);
	// Set the vertical alignment of the label to GUI_VALIGN_BOTTOM
	mTShowName->SetVerticalAlignment(GUIComponent::GUI_VALIGN_BOTTOM);

	mTShowName->SetVisible(true);
	// Add the GUILabel to the GUIComponent  
	shared_ptr<GUIComponent> T_Show_Name_component = static_pointer_cast<GUIComponent>(mTShowName);
	mGameDisplay->GetContainer()->AddComponent(T_Show_Name_component, GLVector2f(0.4f, 0.5f));
	count == 1;
}

void Asteroids::RemoveHighScoreIntrustionGUI() {
	mTShowName->SetVisible(false);
	mEnterName->SetVisible(false);
	mName->SetVisible(false);
	
}
void Asteroids::RemoveStartScreenGUI() {
	mStartGame->SetVisible(false);
	mExitGame->SetVisible(false);
}

void Asteroids::OnScoreChanged(int score)
{
	// Format the score message using an string-based stream
	std::ostringstream msg_stream;
	msg_stream << "Score: " << score;
	// Get the score message as a string
	std::string score_msg = msg_stream.str();
	mScoreLabel->SetText(score_msg);
}

//Writes the Current Score to the File to keep record of scores.
void Asteroids::WriteScore() {
	int score = mScoreKeeper.getmScore();
	cout << "WriteScore" << endl;
	try {
		//opens the file
		fstream file("RecordScore.txt", ios_base::out | ios_base::app);
		//write name score to the file
		file << name << " " << score << endl;
		//close the file
		file.close();
	}
	catch (int e)
	{
		cout << "Error number " << e << endl;
	}
}


//Reads the Top 5 Scores and Display Once the game ends;
void Asteroids::ReadScore() {
	//create vector to store scores
	vector<int> nums;
	
	//cretae string to stores name
	string pName;

	//displays High score Table Title
	mHighScoreTable = shared_ptr<GUILabel>(new GUILabel("Top 5 Highest Scores"));
	mHighScoreTable->SetHorizontalAlignment(GUIComponent::GUI_HALIGN_CENTER);
	mHighScoreTable->SetVerticalAlignment(GUIComponent::GUI_VALIGN_MIDDLE);
	shared_ptr<GUIComponent> high_score_table_component = static_pointer_cast<GUIComponent>(mHighScoreTable);
	mGameDisplay->GetContainer()->AddComponent(high_score_table_component, GLVector2f(0.5f, 0.9f));


	try {
		fstream file;
		file.open("RecordScore.txt");
		
		int num;

		//first word in pName and second in num
		while (file >> pName >> num) {
			//adds the score to the nums vector
			nums.push_back(num);

			//adds the name and the score
			playerRecords[num] = pName;
		}
		//closes the file
		file.close();
		cout << "Success";
		
	}
	//catches exception 
	catch(int e){
		cout << "Error No.: " << e << endl;
	}

	//sorts the vector high to low score
	sort(nums.begin(), nums.end(), std::greater<int>());

	//adds top 5 scores from the nums
	vector<int> top_five(nums.begin(), nums.begin() + min(5, (int)nums.size()));

	//y position of the gui
    float yPos = 0.8f;
	//displays top 5 score
	for (int i = 0; i < top_five.size(); ++i) {
		//displays score
		mPrintScore = shared_ptr<GUILabel>(new GUILabel(to_string(top_five[i])));
		mPrintScore->SetHorizontalAlignment(GUIComponent::GUI_HALIGN_CENTER);
		shared_ptr<GUIComponent> print_score_component = static_pointer_cast<GUIComponent>(mPrintScore);
		mGameDisplay->GetContainer()->AddComponent(print_score_component, GLVector2f(0.7, yPos));

		//displays the player name by using map to find the name by score
		mPrintName = shared_ptr<GUILabel>(new GUILabel(playerRecords[top_five[i]]));
		mPrintName->SetHorizontalAlignment(GUIComponent::GUI_HALIGN_CENTER);
		shared_ptr<GUIComponent> print_name_component = static_pointer_cast<GUIComponent>(mPrintName);
		mGameDisplay->GetContainer()->AddComponent(print_name_component, GLVector2f(0.3, yPos));

		//decreases the yPos by 0.1f
		yPos = yPos - 0.1f;
	}
	
	
}

void Asteroids::OnPlayerKilled(int lives_left)
{
	shared_ptr<GameObject> explosion = CreateExplosion();
	explosion->SetPosition(mSpaceship->GetPosition());
	explosion->SetRotation(mSpaceship->GetRotation());
	mGameWorld->AddObject(explosion);

	// Format the lives left message using an string-based stream
	std::ostringstream msg_stream;
	msg_stream << "Lives: " << lives_left;
	// Get the lives left message as a string
	std::string lives_msg = msg_stream.str();
	mLivesLabel->SetText(lives_msg);

	if (lives_left > 0) 
	{ 
		SetTimer(1000, CREATE_NEW_PLAYER); 
	}
	else
	{
		SetTimer(500, SHOW_GAME_OVER);
	}
}

shared_ptr<GameObject> Asteroids::CreateExplosion()
{
	Animation *anim_ptr = AnimationManager::GetInstance().GetAnimationByName("explosion");
	shared_ptr<Sprite> explosion_sprite =
		make_shared<Sprite>(anim_ptr->GetWidth(), anim_ptr->GetHeight(), anim_ptr);
	explosion_sprite->SetLoopAnimation(false);
	shared_ptr<GameObject> explosion = make_shared<Explosion>();
	explosion->SetSprite(explosion_sprite);
	explosion->Reset();
	return explosion;
}


	



