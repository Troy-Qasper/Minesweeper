using namespace std;
#ifndef minesweeper_header_h
#define minesweeper_header_h
class minesweeper
{
public:
	int tracker = 0;
	int score = 0;
	int xhighlight = 0, yhighlight = 0;
	char initdisplayboard(char t[][10]);
	char printanyboard(char y[][10]);
	char initrealboard(char t[][10]);
	void minegenerator(char t[][10]);
	void player_input(int x, int y, char rea[][10], char disp[][10]);
	void revealwhenx(int x, int y, char rea[][10], char disp[][10]);
	void openbox(int x, int y, char rea[][10], char disp[][10]);
	void flagbox(int x, int y, char rea[][10], char disp[][10]);
	void unflagbox(int x, int y, char rea[][10], char disp[][10]);
	void flagcounter(char disp[][10], char rea[][10]);
	char revealmine(char disp[][10], char rea[][10]);
	int wincon(char rea[][10], char disp[][10]);
	int losecon(char rea[][10], char disp[][10]);
	int scorecalc(char rea[][10], char disp[][10]);
	void hints(int x, int y, char arr[][10]);
	void highlight(int x, int y, char rea[][10], char disp[][10]);
};
#endif