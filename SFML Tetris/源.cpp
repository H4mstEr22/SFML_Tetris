#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>

using namespace std;
using namespace sf;

struct axe {
	int x, y;
};

//////Ruper Rotate System//////
axe ableRotate(int blocktype, int condition, int LorR, axe* smallloc, int biglocx, int biglocy, int frame[10][22])//L:-1 R:1
{
	axe result;
	bool cont = false;
	if (blocktype == 1 || blocktype == 2)//IO
	{
		if (condition == 0)//0
		{
			if (LorR == -1)
			{
				int test[5][2] = { 0,0,2,0,-1,0,-1,-2,2,1 };
				for (int j = 0; j < 5; j++)
				{
					cont = false;
					for (int i = 0; i < 4; i++)
					{
						int x = biglocx + smallloc[i].y + test[j][0], y = biglocy + 3 - smallloc[i].x + test[j][1];
						if (frame[x][y] || x > 9 || x < 0 || y > 21)
						{
							cont = true;
							break;
						}
					}
					if (cont)
					{	
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
			if (LorR == 1)
			{
				int test[5][2] = { 0,0,-2,0,1,0,1,2,-2,1 };
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						if (frame[biglocx + 3-smallloc[i].y + test[j][0]][biglocy + smallloc[i].x + test[j][1]])
						{
							cont = true;
							break;
						}
					}
					if (cont)
					{
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
		}
		if (condition == 1)//R
		{
			if (LorR == -1)
			{
				int test[5][2] = { 0,0,2,0,-1,0,2,-1,-1,2 };
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int x = biglocx + smallloc[i].y + test[j][0], y = biglocy + 3 - smallloc[i].x + test[j][1];
						if (frame[x][y] || x > 9 || x < 0 || y > 21)
						{
							cont = true;
							//break;
						}
					}
					if (cont)
					{
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
			if (LorR == 1)
			{
				int test[5][2] = { 0,0,-1,0,2,0,-1,-2,2,1 };
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int x = biglocx + 3 - smallloc[i].y + test[j][0], y = biglocy + smallloc[i].x + test[j][1];
						if (frame[x][y] || x > 9 || x < 0 || y > 21)
						{
							cont = true;
							break;
						}
					}
					if (cont)
					{
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
		}
		if (condition == 2)//2
		{
			if (LorR == -1)
			{
				int test[5][2] = { 0,0,1,0,-2,0,1,2,-2,-1 };
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int x = biglocx + smallloc[i].y + test[j][0], y = biglocy + 3 - smallloc[i].x + test[j][1];
						if (frame[x][y] || x > 9 || x < 0 || y > 21)
						{
							cont = true;
							break;
						}
					}
					if (cont)
					{
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
			if (LorR == 1)
			{
				int test[5][2] = { 0,0,2,0,-1,0,2,-1,-1,2 };
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int x = biglocx + 3 - smallloc[i].y + test[j][0], y = biglocy + smallloc[i].x + test[j][1];
						if (frame[x][y] || x > 9 || x < 0 || y > 21) 
						{
							cont = true;
							break;
						}
					}
					if (cont)
					{
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
		}
		if (condition == 3)//L
		{
			if (LorR == -1)
			{
				int test[5][2] = { 0,0,-2,0,1,0,-2,1,1,-2 };
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int x = biglocx + smallloc[i].y + test[j][0], y = biglocy + 3 - smallloc[i].x + test[j][1];
						if (frame[x][y] || x > 9 || x < 0 || y > 21)
						{
							cont = true;
							break;
						}
					}
					if (cont)
					{
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
			if (LorR == 1)
			{
				int test[5][2] = { 0,0,1,0,-2,0,1,2,-2,-1 };
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int x = biglocx + 3 - smallloc[i].y + test[j][0], y = biglocy + smallloc[i].x + test[j][1];
						if (frame[x][y] || x > 9 || x < 0 || y > 21) 
						{
							cont = true;
							break;
						}
					}
					if (cont)
					{
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
		}
	}
	else //JLSZT
	{
		if (condition == 0)
		{
			if (LorR == -1)
			{
				int test[5][2] = { 0,0,1,0,1,-1,0,2,1,2 };
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int x = biglocx + smallloc[i].y + test[j][0], y = biglocy + 2 - smallloc[i].x + test[j][1];
						if (frame[x][y] || x > 9 || x < 0 || y > 21)
						{
							cont = true;
							break;
						}
					}
					if (cont)
					{
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
			if (LorR == 1)
			{
				int test[5][2] = { 0,0,-1,0,-1,-1,0,2,-1,2 };
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int x = biglocx + 2 - smallloc[i].y + test[j][0], y = biglocy + smallloc[i].x + test[j][1];
						if (frame[x][y] || x > 9 || x < 0 || y > 21)
						{
							cont = true;
							break;
						}
					}
					if (cont)
					{
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
		}
		if (condition == 1)
		{
			if (LorR == -1)
			{
				int test[5][2] = { 0,0,1,0,1,1,0,-2,1,-2 };
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int x = biglocx + smallloc[i].y + test[j][0], y = biglocy + 2 - smallloc[i].x + test[j][1];
						if (frame[x][y] || x > 9 || x < 0 || y > 21)
						{
							cont = true;
							break;
						}
					}
					if (cont)
					{
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
			if (LorR == 1)
			{
				int test[5][2] = { 0,0,1,0,1,1,0,-2,1,-2 };
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int x = biglocx + 2 - smallloc[i].y + test[j][0], y = biglocy + smallloc[i].x + test[j][1];
						if (frame[x][y] || x > 9 || x < 0 || y > 21)
						{
							cont = true;
							break;
						}
					}
					if (cont)
					{
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
		}
		if (condition == 2)
		{
			if (LorR == -1)
			{
				int test[5][2] = { 0,0,-1,0,-1,-1,0,2,-1,2 };
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int x = biglocx + smallloc[i].y + test[j][0], y = biglocy + 2 - smallloc[i].x + test[j][1];
						if (frame[x][y] || x > 9 || x < 0 || y > 21)
						{
							cont = true;
							break;
						}
					}
					if (cont)
					{
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
			if (LorR == 1)
			{
				int test[5][2] = { 0,0,1,0,1,-1,0,2,1,2 };
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int x = biglocx + 2 - smallloc[i].y + test[j][0], y = biglocy + smallloc[i].x + test[j][1];
						if (frame[x][y] || x > 9 || x < 0 || y > 21)
						{
							cont = true;
							break;
						}
					}
					if (cont)
					{
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
		}
		if (condition == 3)
		{
			if (LorR == -1)
			{
				int test[5][2] = { 0,0,-1,0,-1,1,0,-2,-1,-2 };
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int x = biglocx + smallloc[i].y + test[j][0], y = biglocy + 2 - smallloc[i].x + test[j][1];
						if (frame[x][y] || x > 9 || x < 0 || y > 21)
						{
							cont = true;
							break;
						}
					}
					if (cont)
					{
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
			if (LorR == 1)
			{
				int test[5][2] = { 0,0,-1,0,-1,1,0,-2,-1,-2 };
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						int x = biglocx + 2 - smallloc[i].y + test[j][0], y = biglocy + smallloc[i].x + test[j][1];
						if (frame[x][y] || x > 9 || x < 0 || y > 21)
						{
							cont = true;
							break;
						}
					}
					if (cont)
					{
						cont = false;
						continue;
					}
					result.x = test[j][0];
					result.y = test[j][1];
					return result;
				}
			}
		}
	}

	result.x = 5; result.y = 5;

	return result;
}



int main()
{
	RenderWindow window(VideoMode(720, 840), "Tetris", Style::Close);

	//////Textures//////
	Texture Itexture;
	Itexture.loadFromFile("texture/I.png");
	Texture Otexture;
	Otexture.loadFromFile("texture/O.png");
	Texture Jtexture;
	Jtexture.loadFromFile("texture/J.png");
	Texture Ltexture;
	Ltexture.loadFromFile("texture/L.png");
	Texture Stexture;
	Stexture.loadFromFile("texture/S.png");
	Texture Ztexture;
	Ztexture.loadFromFile("texture/Z.png");
	Texture Ttexture;
	Ttexture.loadFromFile("texture/T.png");
	Texture allTexture[8] = { Itexture , Itexture, Otexture, Jtexture, Ltexture ,Stexture ,Ztexture ,Ttexture };

	Texture ItextureTrans;
	ItextureTrans.loadFromFile("texture/Itrans.png");
	Texture OtextureTrans;
	OtextureTrans.loadFromFile("texture/Otrans.png");
	Texture JtextureTrans;
	JtextureTrans.loadFromFile("texture/Jtrans.png");
	Texture LtextureTrans;
	LtextureTrans.loadFromFile("texture/Ltrans.png");
	Texture StextureTrans;
	StextureTrans.loadFromFile("texture/Strans.png");
	Texture ZtextureTrans;
	ZtextureTrans.loadFromFile("texture/Ztrans.png");
	Texture TtextureTrans;
	TtextureTrans.loadFromFile("texture/Ttrans.png");
	Texture allTextureTrans[8] = { ItextureTrans , ItextureTrans, OtextureTrans, JtextureTrans, LtextureTrans ,StextureTrans ,ZtextureTrans ,TtextureTrans };

	//////Sounds//////
	SoundBuffer MoveSound;
	MoveSound.loadFromFile("sounds/Move.wav");
	Sound Movesound;
	Movesound.setBuffer(MoveSound);
	SoundBuffer AutoDropSound;
	AutoDropSound.loadFromFile("sounds/AutoDrop.wav");
	Sound Autodropsound;
	Autodropsound.setBuffer(AutoDropSound);
	SoundBuffer DoubleSound;
	DoubleSound.loadFromFile("sounds/Line.wav");
	Sound Doublesound;
	Doublesound.setBuffer(DoubleSound);
	SoundBuffer HardDropSound;
	HardDropSound.loadFromFile("sounds/HardDrop.wav");
	Sound Harddropsound;
	Harddropsound.setBuffer(HardDropSound);
	SoundBuffer LineSound;
	LineSound.loadFromFile("sounds/Line.wav");
	Sound Linesound;
	Linesound.setBuffer(LineSound);
	SoundBuffer RotateSound;
	RotateSound.loadFromFile("sounds/Rotate.wav");
	Sound Rotatesound;
	Rotatesound.setBuffer(RotateSound);
	SoundBuffer SoftdropSound;
	SoftdropSound.loadFromFile("sounds/SoftDrop.wav");
	Sound Softdropsound;
	Softdropsound.setBuffer(SoftdropSound);
	SoundBuffer TetrisSound;
	TetrisSound.loadFromFile("sounds/Tetris.wav");
	Sound Tetrissound;
	Tetrissound.setBuffer(TetrisSound);
	SoundBuffer HoldSound;
	HoldSound.loadFromFile("sounds/Hold.wav");
	Sound Holdsound;
	Holdsound.setBuffer(HoldSound);
	SoundBuffer TspinSound;
	TspinSound.loadFromFile("sounds/Tspin.wav");
	Sound Tspinsound;
	Tspinsound.setBuffer(TspinSound);
	SoundBuffer SpinSound;
	SpinSound.loadFromFile("sounds/Spin.wav");
	Sound Spinsound;
	Spinsound.setBuffer(SpinSound);
	SoundBuffer BTBSound;
	BTBSound.loadFromFile("sounds/BTB.wav");
	Sound BTBsound;
	BTBsound.setBuffer(BTBSound);
	SoundBuffer PCSound;
	PCSound.loadFromFile("sounds/PC.wav");
	Sound PCsound;
	PCsound.setBuffer(PCSound);

	//////Fonts//////
	Font Dearest;
	Dearest.loadFromFile("fonts/Dearest.ttf");
	Font Elegant;
	Elegant.loadFromFile("fonts/Elegant.ttf"); 
	Font RIVERFLOWS;
	RIVERFLOWS.loadFromFile("fonts/RIVERFLOWS.ttf");
	Font Caress;
	Caress.loadFromFile("fonts/Caress.ttf");

	//////Texts//////
	Text TSpin;
	TSpin.setFont(Caress);
	TSpin.setString("T-SPIN");
	TSpin.setCharacterSize(30);
	TSpin.setFillColor(Color(255,0,238));
	TSpin.setPosition(40,540);
	Text PerfectClear;
	PerfectClear.setFont(Elegant);
	PerfectClear.setString("PERFECT CLEAR!");
	PerfectClear.setCharacterSize(60);
	PerfectClear.setFillColor(Color(255, 145, 5));
	PerfectClear.setPosition(155,500);
	PerfectClear.setStyle(Text::Bold);
	Text Tetris;
	Tetris.setFont(Caress);
	Tetris.setString("TETRIS");
	Tetris.setCharacterSize(30);
	Tetris.setFillColor(Color(0, 211, 244));
	Tetris.setPosition(35,480);
	Text BackToBack;
	BackToBack.setFont(Caress);
	BackToBack.setString("BACK TO BACK");
	BackToBack.setCharacterSize(24);
	BackToBack.setFillColor(Color(64, 0, 255));
	BackToBack.setPosition(0,420);
	Text Score;
	Score.setFont(Elegant);
	Score.setCharacterSize(24);
	Score.setFillColor(Color(255, 255, 255));
	Score.setPosition(0,600);
	long long int scoreCount = 0;
	string scorestring;
	float TSpinshowtime = 0, PerfectClearshowtime = 0, Tetrisshowtime = 0, BackToBackshowtime = 0;
	

	RectangleShape block(Vector2f(40, 40));
	RectangleShape blocktrans(Vector2f(40, 40));
	RectangleShape Nextblock(Vector2f(30, 30));
	RectangleShape Holdblock(Vector2f(30, 30));
	//block.setTexture(&Itexture);

	RectangleShape nextBG(Vector2f(160, 840));
	nextBG.setFillColor(Color(100,100,100));
	nextBG.setPosition(560, 0);
	RectangleShape holdBG(Vector2f(160, 840));
	holdBG.setFillColor(Color(100, 100, 100));
	holdBG.setPosition(0, 0);
	RectangleShape Line1(Vector2f(2, 840));
	Line1.setFillColor(Color(230, 230, 230));
	RectangleShape Line2(Vector2f(400, 2));
	Line2.setFillColor(Color(230, 230, 230));
	RectangleShape Line3(Vector2f(400, 2));
	Line3.setFillColor(Color(200, 200, 200));

	int figure[8][4] = {
		0, 0, 0, 0,
		4, 5, 6, 7, //I
		5, 6, 9, 10, //O
		0, 4, 5, 6, //J
		2, 4, 5, 6, //L
		1, 2, 4, 5, //S
		0, 1, 5, 6, //Z
		1, 4, 5, 6  //T
	};

	axe smallloc[4];
	axe nsmallloc[4];

	int frame[10][22] = { 0 };

	for (int i = 0; i < 4; i++)
	{
		smallloc[i].x = 0;
		smallloc[i].y = 0;
	}

	int biglocx, biglocy, kind, nextkind, holdkind = 0;

	//////time//////
	Clock clock;
	Clock blockclock;
	clock.restart();
	blockclock.restart();
	int blockTime;
	float deltaTime;
	
	float lefttime = 0, righttime = 0, downtime = 0.1, leftswitchtime = 0.02, rightswitchtime = 0.02, downswitchtime = 0.03, holdtime = 0.15, gswitchtime = 0.5, gtime = 0, textShowtime = 1, autonexttime = 0.5;
	bool rotateLeft = false, rotateRight = false, ableRotateLeft, ableRotateRight, ableMoveDown, ableMoveLeft, ableMoveRight, newone = true, gdown = true, HDflag = false, hold = false, restart = false;
	bool Apress = false, Spress = false, Dpress = false, Wpress = false, Lpress = false, Rpress = false, Hpress = false, Repress = false;
	int condition = 0;
	bool HoldLimit = true, specialSpin = false, isLastRotate = false, specialclear = false, PC = false;

	//////7bag//////
	int bag7[8] = { 0,1,2,3,4,5,6,7 };
	int cnt = 0;

	int next[5] = { 0 };
	bool nextisempty = true;


	while (window.isOpen())
	{
		deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		//////Draw the Background//////
		window.clear(Color::White);
		window.draw(nextBG);
		window.draw(holdBG);
		//////Draw the Lines//////
		for (int i = 0; i < 9; i++)
		{
			Line1.setPosition(199 + i * 40, 0);
			window.draw(Line1);
		}
		for (int i = 1; i < 20; i++)
		{
			Line2.setPosition(160, 39 + i * 40);
			window.draw(Line2);
		}
		Line3.setPosition(160, 39);
		window.draw(Line3);



		Event evnt;

		//////New Blocks//////
		if (newone)
		{
			HoldLimit = true;
			if (Hpress)
			{
				HoldLimit = false;
			}
			gtime = 0;
			condition = 0;
			
			if (nextisempty)
			{
				for (int i = 0; i < 5; i++)
				{
					cnt++;
					do
					{
						blockTime = blockclock.getElapsedTime().asMicroseconds();
						next[i] = bag7[blockTime % 7 + 1];
						bag7[next[i]] = 0;
					} while (next[i] == 0);
				}
				nextisempty = false;
			}

			kind = next[0];
			for (int i = 0; i < 4; i++)
			{
				next[i] = next[i + 1];
			}
			next[4] = 0;
			do
			{
				blockTime = blockclock.getElapsedTime().asMicroseconds();
				next[4] = bag7[blockTime % 7 + 1];
				bag7[next[4]] = 0;
			} while (next[4] == 0);
			cnt++;
			
			if(cnt == 7)
			{
				for (int i = 1; i < 8; i++)
				{
					bag7[i] = i;
				}
				cnt = 0;
			}
			biglocx = 3, biglocy = 0;
			for (int i = 0; i < 4; i++)
			{
				smallloc[i].x = figure[kind][i] % 4;
				smallloc[i].y = figure[kind][i] / 4;
				if (frame[biglocx + smallloc[i].x][biglocy + smallloc[i].y])
				{
					restart = true;
					break;
				}
			}
			newone = false;
		}
		
		ableMoveDown = true; ableMoveLeft = true; ableMoveRight = true; ableRotateLeft = true; ableRotateRight = true;

		

		while (window.pollEvent(evnt))
		{
			if (evnt.type == Event::Closed)
				window.close();

			if (evnt.type == Event::KeyPressed)
			{
				///////Move///////
				if (evnt.key.code == Keyboard::S)//down
				{
					Spress = true;
					
				}
				if (evnt.key.code == Keyboard::A)//left
				{
					if (!Apress)
					{
						lefttime = leftswitchtime - holdtime;
						Apress = true;
						for (int i = 0; i < 4; i++)
						{
							int blx = biglocx + smallloc[i].x, bly = biglocy + smallloc[i].y;
							if (blx == 0 || frame[blx - 1][bly])
								ableMoveLeft = false;
						}
						if (ableMoveLeft)
						{
							biglocx -= 1;
							if (!gdown)
							{
								gtime = 0;
								//gdown = true;
							}
							Movesound.play();
						}
					}
				}
				if (evnt.key.code == Keyboard::D)//right
				{
					if (!Dpress)
					{
						righttime = rightswitchtime - holdtime;
						Dpress = true;
						for (int i = 0; i < 4; i++)
						{
							int blx = biglocx + smallloc[i].x, bly = biglocy + smallloc[i].y;
							if (blx == 10 || frame[blx + 1][bly])
								ableMoveRight = false;
						}
						if (ableMoveRight)
						{
							biglocx += 1;
							if (!gdown)
							{
								gtime = 0;
								//gdown = true;
							}
							Movesound.play();
						}
					}
				}
				if (evnt.key.code == Keyboard::W)//HardDrop
				{
					if (!Wpress)
					{
						Wpress = true;
						HDflag = true;
					}
				}

				//////ifRotate//////
				if (evnt.key.code == Keyboard::Left)//left
				{
					if (!Lpress)
					{
						rotateLeft = true;
						Lpress = true;
					}
				}
				if (evnt.key.code == Keyboard::Up)//right
				{
					if (!Rpress)
					{
						rotateRight = true;
						Rpress = true;
					}
				}

				//////isHold//////
				if (evnt.key.code == Keyboard::Space)
				{
					if (!Hpress)
					{
						Hpress = true;
						hold = true;
					}
				}

				//////Restart//////
				if (evnt.key.code == Keyboard::R)
				{
					if (!Repress)
					{
						Repress = true;
						restart = true;
					}
				}
			}

			if (evnt.type == Event::KeyReleased)
			{
				if (evnt.key.code == Keyboard::S)
				{
					Spress = false;
					downtime = downswitchtime;
				}
				if (evnt.key.code == Keyboard::A)
				{
					Apress = false;
				}
				if (evnt.key.code == Keyboard::D)
				{
					Dpress = false;
				}
				if (evnt.key.code == Keyboard::W)
				{
					Wpress = false;
				}
				if (evnt.key.code == Keyboard::Left)
				{
					Lpress = false;
				}
				if (evnt.key.code == Keyboard::Up)
				{
					Rpress = false;
				}
				if (evnt.key.code == Keyboard::Space)
				{
					Hpress = false;
				}
				if (evnt.key.code == Keyboard::R)
				{
					Repress = false;
				}
			}

		}

		//////Restart//////
		if (Repress || restart)
		{
			scoreCount = 0;
			restart = false;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 22; j++)
				{
					frame[i][j] = 0;
				}
			}
			cnt = 0;
			
			for (int i = 0; i < 8; i++)
				bag7[i] = i;
			for (int i = 0; i < 5; i++)
				next[i] = 0;
			newone = true;
			gdown = true;
			gtime = 0;
			isLastRotate = false;
			specialclear = false;
			specialSpin = false;
			HoldLimit = true;
			nextisempty = true;
			holdkind = 0;
			continue;
		}

		//////Move//////
		if (Spress)//down
		{
			if (downtime >= downswitchtime)
			{
				downtime -= downswitchtime;
				for (int i = 0; i < 4; i++)
				{
					int blx = biglocx + smallloc[i].x, bly = biglocy + smallloc[i].y;
					if (bly == 21 || frame[blx][bly + 1])
						ableMoveDown = false;
				}
				if (ableMoveDown)
				{
					gtime = 0;
					biglocy++;
					scoreCount++;
					Softdropsound.play();
					isLastRotate = false;
				}
			}
			else
				downtime += deltaTime;
		}
		if (Apress)//left
		{
			if (lefttime >= leftswitchtime)
			{
				lefttime -= leftswitchtime;
				for (int i = 0; i < 4; i++)
				{
					int blx = biglocx + smallloc[i].x, bly = biglocy + smallloc[i].y;
					if (blx == 0 || frame[blx - 1][bly])
						ableMoveLeft = false;
				}
				if (ableMoveLeft)
				{
					biglocx -= 1;
					if (!gdown)
					{
						//gtime = 0;
						gdown = true;
					}
					Movesound.play();
					isLastRotate = false;
				}

			}
			else
				lefttime += deltaTime;
		}
		if (Dpress)//right
		{
			if (righttime >= rightswitchtime)
			{
				righttime -= rightswitchtime;
				for (int i = 0; i < 4; i++)
				{
					int blx = biglocx + smallloc[i].x, bly = biglocy + smallloc[i].y;
					if (blx == 10 || frame[blx + 1][bly])
						ableMoveRight = false;
				}
				if (ableMoveRight)
				{
					biglocx += 1;
					if (!gdown)
					{
						//gtime = 0;
						gdown = true;
					}
					Movesound.play();
					isLastRotate = false;
				}

			}
			else
				righttime += deltaTime;
		}
		

		//////Rotate//////
		if (rotateLeft && Lpress)
		{
			axe isRotatable = ableRotate(kind, condition, -1, smallloc, biglocx, biglocy, frame);
			if (isRotatable.x != 5)
			{
				condition +=3;
				condition = condition % 4;
				biglocx += isRotatable.x; biglocy += isRotatable.y;
				if (kind == 1 || kind == 2)
				{
					for (int i = 0; i < 4; i++)
					{
						int tempx = smallloc[i].x;
						smallloc[i].x = smallloc[i].y;
						smallloc[i].y = 3 - tempx;
					}
				}
				else
				{
					for (int i = 0; i < 4; i++)
					{
						int tempx = smallloc[i].x;
						smallloc[i].x = smallloc[i].y;
						smallloc[i].y = 2 - tempx;
					}
				}
				if (gdown == false)
				{
					gtime = 0;
					//gdown = true;
				}
				Rotatesound.play();
				isLastRotate = true;
			}
			rotateLeft = false;
		} 
		if (rotateRight && Rpress)
		{
			axe isRotatable = ableRotate(kind, condition, 1, smallloc, biglocx, biglocy, frame);
			if (isRotatable.x != 5)
			{
				condition += 1;
				condition = condition % 4;
				biglocx += isRotatable.x; biglocy += isRotatable.y;
				if (kind == 1 || kind == 2)
				{
					for (int i = 0; i < 4; i++)
					{
						int tempy = smallloc[i].y;
						smallloc[i].y = smallloc[i].x;
						smallloc[i].x = 3 - tempy;
					}
				}
				else
				{
					for (int i = 0; i < 4; i++)
					{
						int tempy = smallloc[i].y;
						smallloc[i].y = smallloc[i].x;
						smallloc[i].x = 2 - tempy;
					}
				}
				if (gdown == false)
				{
					gtime = 0;
					//gdown = true;
				}
				Rotatesound.play();
				isLastRotate = true;
			}
			rotateRight = false;
		}

		//////Hold//////
		if (hold && Hpress && HoldLimit)
		{
			HoldLimit = false;
			hold = false;
			if (holdkind == 0)
			{
				newone = true;
				holdkind = kind;
			}
			else
			{
				int tmp = holdkind;
				holdkind = kind;
				kind = tmp;
				biglocx = 3, biglocy = 0;
				for (int i = 0; i < 4; i++)
				{
					smallloc[i].x = figure[kind][i] % 4;
					smallloc[i].y = figure[kind][i] / 4;
					if (frame[biglocx + smallloc[i].x][biglocy + smallloc[i].y])
					{
						window.close();
						break;
					}
				}
			}
			Holdsound.play();
			isLastRotate = false;
		}
		
		
		//////Auto Down//////
		gdown = true;
		if (gdown)
		{
			for (int i = 0; i < 4; i++)
			{
				int blx = biglocx + smallloc[i].x, bly = biglocy + smallloc[i].y;
				if (bly == 21 || frame[blx][bly + 1] != 0)
				{
					gdown = false;

					break;
				}
			}
		}
		if (gtime >= gswitchtime)
		{
			
			if (gdown == false)
			{
				if (gtime >= autonexttime)
				{
					gtime -= autonexttime;
					newone = true;
					for (int i = 0; i < 4; i++)
					{
						frame[biglocx + smallloc[i].x][biglocy + smallloc[i].y] = kind;
					}
					blockclock.restart();
					gdown = true;
					Autodropsound.play();
				}
				else gtime += deltaTime;
			}
			else
			{
				gtime -= gswitchtime;
				biglocy += 1;
				isLastRotate = false;
			}

		}
		else
		{
			gtime += deltaTime;
		}

		//////Harddrop//////
		if (Wpress && HDflag)
		{
			bool KeepDown = true;
			while (KeepDown)
			{
				for (int i = 0; i < 4; i++)
				{
					int blx = biglocx + smallloc[i].x, bly = biglocy + smallloc[i].y;
					if (bly == 21 || frame[blx][bly + 1])
					{
						KeepDown = false;
						break;
					}
				}
				if (KeepDown)
				{
					biglocy += 1;
					scoreCount += 2;
					isLastRotate = false;
				}
			}
			newone = true;
			for (int i = 0; i < 4; i++)
			{
				frame[biglocx + smallloc[i].x][biglocy + smallloc[i].y] = kind;

			}
			blockclock.restart();
			HDflag = false;
			gtime = 0;
			gdown = true;
			Harddropsound.play();
			
		}

		//////is Tspin//////
		if (newone && kind == 7)
		{
			int anglecnt = 0;
			if (frame[biglocx][biglocy] || biglocx < 0 || biglocx>9 || biglocy > 21) anglecnt++;
			if (frame[biglocx + 2][biglocy + 2] || biglocx + 2 < 0 || biglocx + 2 > 9 || biglocy + 2 > 21) anglecnt++;
			if (frame[biglocx + 2][biglocy] || biglocx + 2 < 0 || biglocx + 2 > 9 || biglocy > 21) anglecnt++;
			if (frame[biglocx][biglocy + 2] || biglocx < 0 || biglocx > 9 || biglocy + 2 > 21) anglecnt++;
			if (anglecnt >= 3 && isLastRotate)
			{
				if (specialclear)
				{
					BackToBackshowtime = textShowtime;
				}
				specialSpin = true;
				TSpinshowtime = textShowtime;
			}
			else specialSpin = false;
		}

		

		//////Clear Line//////
		int linenum = 0;
		for (int i = 0; i < 22; i++)
		{
			bool clearflag = true;
			for (int j = 0; j < 10; j++)
			{
				if (!frame[j][i])
				{
					clearflag = false;
					break;
				}
			}
			if (clearflag)
			{
				linenum++;
				for (int line = i; line > 0; line--)
				{
					for (int single = 0; single < 10; single++)
					{
						frame[single][line] = frame[single][line - 1];
					}
				}
				for (int single = 0; single < 10; single++)
				{
					frame[single][0] = 0;
				}
			}
		}
		if (linenum == 1)
		{
			if (specialSpin)
			{
				if (specialclear)
				{
					BTBsound.play();
					scoreCount += 400;
				}
				else
				{
					Tspinsound.play();
					specialclear = true;
					scoreCount += 300;
				}
			}
			else
			{
				scoreCount += 40;
				Linesound.play();
				specialclear = false;
			}
		}
		else if (linenum == 4)
		{
			if (specialclear)
			{
				BTBsound.play();
				BackToBackshowtime = textShowtime;
				scoreCount += 700;
			}
			else
			{
				Tetrissound.play();
				scoreCount += 500;  
			}
			specialclear = true;
			Tetrisshowtime = textShowtime;
		}
		else if (linenum == 2 || linenum == 3)
		{
			if (specialSpin)
			{                                                                                                                                                      
				if (specialclear)
				{
					BTBsound.play();
					if (linenum == 2)
						scoreCount += 800;
					if (linenum == 3)
						scoreCount += 1200;
				}
				else
				{
					Tspinsound.play();
					if (linenum == 2)
						scoreCount += 600;
					if (linenum == 3)
						scoreCount += 1000;
				}
				specialclear = true;
			}
			else
			{
				if (linenum == 2)
					scoreCount += 100;
				if (linenum == 3)
					scoreCount += 200;
				Doublesound.play();
				specialclear = false;
			}
		}
		else if (specialSpin)
		{
			scoreCount += 150;
			specialclear = true;
			Spinsound.play();
		}
		if (linenum)//isPerfectClear
		{
			PC = true;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 22; j++)
				{
					if (frame[i][j])
					{
						PC = false;
						break;
					}
				}
			}
			if (PC)
			{
				PCsound.play();
				PerfectClearshowtime = textShowtime;
				scoreCount += 2000;
			}
		}
		specialSpin = false;
		
		
		//////Draw the Moving Blocks//////
		block.setTexture(&allTexture[kind]);
		for (int i = 0; i < 4; i++)
		{
			block.setPosition((smallloc[i].x + biglocx) * 40 + 160, (smallloc[i].y + biglocy-1) * 40);
			window.draw(block);
		}

		//////Confirm the TransBlock's loc//////
		int translocy = biglocy-1;
		int transdownable = true;
		while (transdownable)
		{
			translocy++;
			for (int i = 0; i < 4; i++)
			{
				int blx = biglocx + smallloc[i].x, bly = translocy + smallloc[i].y;
				if (bly == 21 || frame[blx][bly + 1])
					transdownable = false;
			}	
		}
		//////Draw the Transparent Blocks//////
		blocktrans.setTexture(&allTextureTrans[kind]);
		for (int i = 0; i < 4; i++)
		{
			blocktrans.setPosition((smallloc[i].x + biglocx) * 40 + 160, (smallloc[i].y + translocy - 1) * 40);
			window.draw(blocktrans);
		}

		//////Draw the Static Blocks//////
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 22; j++)
			{
				if(frame[i][j])
				{
					block.setTexture(&allTexture[frame[i][j]]);
					block.setPosition(i * 40 + 160, (j-1) * 40);
					window.draw(block);
				}
			}
		}

		//////Draw the Nextlist Blocks//////
		for (int i = 0; i < 5; i++)
		{
			nextkind = next[i];
			Nextblock.setTexture(&allTexture[nextkind]);
			
			for (int j = 0; j < 4; j++)
			{
				nsmallloc[j].x = figure[nextkind][j] % 4;
				nsmallloc[j].y = figure[nextkind][j] / 4;
			}
			for (int j = 0; j < 4; j++)
			{
				Nextblock.setPosition(580 + nsmallloc[j].x*30, 120 * i + nsmallloc[j].y*30);
				window.draw(Nextblock);
			}
		}

		//////Draw the Holding Block//////
		if (holdkind != 0)
		{
			Holdblock.setTexture(&allTexture[holdkind]);
			for (int j = 0; j < 4; j++)
			{
				nsmallloc[j].x = figure[holdkind][j] % 4;
				nsmallloc[j].y = figure[holdkind][j] / 4;
			}
			for (int j = 0; j < 4; j++)
			{
				Holdblock.setPosition(20 + nsmallloc[j].x * 30, 30 + nsmallloc[j].y * 30);
				window.draw(Holdblock);
			}
		}

		//////Print the Texts//////
		if (TSpinshowtime > 0)
		{
			window.draw(TSpin);
			TSpinshowtime -= deltaTime;
		}
		if (Tetrisshowtime > 0)
		{
			window.draw(Tetris);
			Tetrisshowtime -= deltaTime;
		}
		if (BackToBackshowtime > 0)
		{
			window.draw(BackToBack);
			BackToBackshowtime -= deltaTime;
		}
		if (PerfectClearshowtime > 0)
		{
			window.draw(PerfectClear);
			PerfectClearshowtime -= deltaTime;
		}

		long long int now = scoreCount;
		string sn = "";
		char nownum;
		while (now != 0)
		{
			nownum = '0' + now % 10;
			sn = nownum + sn;
			now = now / 10;
		}
		scorestring = "Tetris [score: " + sn + "]";
		window.setTitle(scorestring);


		
		window.display();
	}

	

	return 0;
}