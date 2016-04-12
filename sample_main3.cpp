#include "std_lib_facilities_3.h"
#include "Simple_window.h"
#include "Graph.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
//all global variables
using namespace Graph_lib;
using namespace std;
int kil=1;
int rand_oper;
int rand_j;
const int n = 8;
char board[n][n];
char board2[n][n];
char x = 'X';
char a = 'A';
char b = 'B';
char c = 'C';
int roomable=0;
char d = 'D';
int players=0;
char plays;
int ksl=9;
int cker=0;
int rk,ck;
int save_rks;
int current_i;
int current_jk;
int palyer_rand;
char ai;
char copy_board[n][n];
int rks=0;
string prints;
stringstream ss;
stringstream s3;
stringstream ss1;

int final_x;
int final_y;
int make_x;
vector<string>datas;
vector<string>datanumber;

int make_y;
int flag=0;
int check_i;
int check_j;
int mk;
int read_score;
int wining;
string player_name;
static int counter=0;
Vector_ref<Text> tl;
Vector_ref<Circle> cl;
Vector_ref<Circle> bl;
Vector_ref<Circle> al;
Vector_ref<Circle> dl;
Vector_ref<Circle> xl;
Vector_ref<Text> t1;
Vector_ref<Text> t2;
Vector_ref<Text> t3;
Vector_ref<Text> t4;
Vector_ref<Text> t5;
Vector_ref<Text> t6;

//high score window
struct win3 : Simple_window
{
	win3(Point xy, int w, int h, const string& title);
	
	Button hs;
	Vector_ref<Text> t1;
	Vector_ref<Text> t2;
	Vector_ref<Text> t3;
	Vector_ref<Text> t4;
	Vector_ref<Text> t5;
	Vector_ref<Text> t6;
	
	static void cb_hs(Address, Address);
	void hss();
};
win3::win3(Point xy, int w, int h, const string& title)
:Simple_window(xy,w,h,title),

hs(Point(100,400),150,30,"Scoring",cb_hs)
{
	attach(hs);
}
void win3::cb_hs(Address, Address pw){
	reference_to<win3>(pw).hss();
}
void win3::hss(){
		
	vector<string>datas;
	vector<string>datanumber;
	ifstream filename;
	
	string read;
	string readscore;
	filename.open("scores.txt");
	cout<<"dsdsddsd"<<endl;
	if(filename.is_open()){
		while(filename.good()) // To get you all the lines.
        {
		getline(filename, read);
		datas.push_back(read);
			cout<<read<<endl;
			getline(filename,readscore);
			datanumber.push_back(readscore);
			cout<<readscore<<endl;
		}
		//cout <<< read << endl;
	}
	filename.close();
	for(int i=0;i<datas.size();i++)
	{
		cout<<datas[i]<<endl;
		cout<<datanumber[i]<<endl;
	}
	
	t6.push_back(new Text(Point(120,50),"HIGH SCORE"));
	t6[t6.size()-1].set_font_size(40);
	attach(t6[t6.size()-1]);
	
	t6.push_back(new Text(Point(100,130),"NAME"));
	t6[t6.size()-1].set_font_size(30);
	attach(t6[t6.size()-1]);
	
	t6.push_back(new Text(Point(250,130),"SCORE"));
	t6[t6.size()-1].set_font_size(30);
	attach(t6[t6.size()-1]);
	
	redraw();
	t1.push_back(new Text(Point(100,160),datas[0]));
	t1[t1.size()-1].set_font_size(20);
		attach(t1[t1.size()-1]);
	t1.push_back(new Text(Point(250,160),datanumber[0]));
	t1[t1.size()-1].set_font_size(20);
	attach(t1[t1.size()-1]);
	
	t2.push_back(new Text(Point(100,240),datas[1]));
	t2[t2.size()-1].set_font_size(20);
	attach(t2[t2.size()-1]);
	t2.push_back(new Text(Point(250,240),datanumber[1]));
	t2[t2.size()-1].set_font_size(20);
	attach(t2[t2.size()-1]);
	
	t3.push_back(new Text(Point(100,280),datas[2]));
	t3[t3.size()-1].set_font_size(20);
	attach(t3[t3.size()-1]);
	
	t3.push_back(new Text(Point(250,280),datanumber[2]));
	t3[t3.size()-1].set_font_size(20);
	attach(t3[t3.size()-1]);
	
	t4.push_back(new Text(Point(100,320),datas[3]));
	t4[t4.size()-1].set_font_size(20);
	attach(t4[t4.size()-1]);
	t4.push_back(new Text(Point(250,320),datanumber[3]));
	t4[t4.size()-1].set_font_size(20);
	attach(t4[t4.size()-1]);
	
	t5.push_back(new Text(Point(100,360),datas[4]));
	t5[t5.size()-1].set_font_size(20);
	attach(t5[t5.size()-1]);
	t5.push_back(new Text(Point(250,360),datanumber[4]));
	t5[t5.size()-1].set_font_size(20);
	attach(t5[t5.size()-1]);
//
	
}
//---------------------------------------------------------------------------------
//ask for a name window
struct win2 : Simple_window
{
	win2(Point xy, int w, int h, const string& title);

private:
	In_box name1;
	Button enter_button;
	
	static void cb_enter(Address, Address);
	void enter();
};
win2::win2(Point xy, int w, int h, const string& title)
:Simple_window(xy,w,h,title),

enter_button(Point(100,55),150,30,"Enter",cb_enter),
name1(Point(70,10),200,30,"Name: " )
{
	attach(enter_button);
	attach(name1);
}
void win2::cb_enter(Address, Address pw){
	reference_to<win2>(pw).enter();
}
void win2::enter(){
	player_name = name1.get_string();
	cout << player_name << endl;
	hide();
}
//----------------------------------------------------------------------------------
//Complete game window
struct win1 : Simple_window
{
	win1(Point xy, int w, int h, const string& title);

private:
	Button play_button;
	Button load_button;
	Button rules_button;
	Button scores_button;
	Button quit_button;
	Button QB_button;
	Button LM_button;
	Button back_button;
	Button back2_button;
	Image bg;
	Image bg1;
	Image bgrules;
	Text count;
	Text score;
	Text score1;

	public:
	static void cb_play(Address, Address);
	void play();
	static void cb_load(Address, Address);
	void load();
	static void cb_rules(Address, Address);
	void rules();
	static void cb_scores(Address, Address);
	void scores();
	static void cb_quit(Address, Address);
	void quit();
	static void cb_qb(Address, Address);
	void qb();
	static void cb_lm(Address, Address);
	void lm();
	static void cb_back(Address, Address);
	void back();
	static void cb_back2(Address, Address);
	void back2();
	static void cb_click5(Address, Address);
	static void cb_click(Address, Address);
	static void cb_click2(Address, Address);
	static void cb_click4(Address, Address);
	bool check(char board2[n][n],int c, int k);
	bool determine(char board[n][n]);
	void set_move(int c, int r);
	void set_move2(int c, int r);
	void copy_boardarray(char board[n][n], char copy_board[n][n]);
	void initialize();
	void display(gameboard& test);
	void choseplayer(char board2[n][n], int &rk,int &ck,char plays);
	bool check2(char board2[n][n], int c1, int k, char plays);
	void players3();
	void players4();
	void game_intial();
	void player_chose();
	int  find_i(char board[n][n], int &i, int &k);
	bool check_second(char board2[n][n], int c1, int k);
	void start_game();
	void findplay (char board2[n][n],int i, int j);
	bool max_path(char board[n][n],int fin, int finy,int &result );
	void scoring(int a);
	void read_file();
	void write_file();
	
};
//---------------------------------------------------------------------------------
//Win1 Constructor
win1::win1(Point xy, int w, int h, const string& title)
:Simple_window(xy,w,h,title),

bg(Point(0,0), "MScreen.jpg"),
bg1(Point(0,0),"win2.jpg"),
bgrules(Point(0,0),"rules.jpg"),
//name1(Point(860,25),150,30,"Name: "),
count(Point(820,105),"Count: "),
score(Point(820,145),"Score: "),
//count1(Point(900,105),""),
score1(Point(900,145),""),


play_button   (Point(70,150),257,85,"New Game", cb_play),
load_button   (Point(70,250),257,85,"Load Game", cb_load),
rules_button  (Point(70,360),257,85,"Rules",cb_rules),
scores_button (Point(70,460),257,85,"High Scores",cb_scores),
quit_button   (Point(70,565),257,85,"Quit",cb_quit),
QB_button     (Point(302,425),400,83,"Quarter Back", cb_qb),
LM_button     (Point(302,538),398,80,"Lineman", cb_lm),
back_button   (Point(20,590),213,66,"Back",cb_back),
back2_button  (Point(20,590),213,66,"Back",cb_back2)
{
	bg.set_mask(Point(0,0),1024,675);
	attach(bg);
	count.set_font_size(20);
	score.set_font_size(20);
	score1.set_font_size(20);
	attach(quit_button);
	attach(play_button);
	attach(load_button);
	attach(rules_button);
	attach(scores_button);
}
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void win1::cb_play(Address, Address pw){// callback for play button
	reference_to<win1>(pw).play();
}
void win1::play(){//play function
	detach(bg);
	detach(play_button);
	detach(load_button);
	detach(scores_button);
	detach(quit_button);
	detach(rules_button);
	attach(bg1);
	attach(QB_button);
	attach(LM_button);
	attach(back_button);
}
void win1::cb_load(Address, Address pw){
	reference_to<win1>(pw).load();
}
void win1::load(){
	detach(bg);
	detach(play_button);
	detach(load_button);
	detach(scores_button);
	detach(quit_button);
	detach(rules_button);
	attach(bg1);
	attach(QB_button);
	attach(LM_button);
	attach(back_button);
}
void win1::cb_rules(Address, Address pw){//callback for rules button
	reference_to<win1>(pw).rules();
}
void win1::rules(){//rules function
	detach(bg);
	detach(play_button);
	detach(load_button);
	detach(scores_button);
	detach(quit_button);
	detach(rules_button);
	attach(bgrules);
	attach(back2_button);
}
void win1::cb_scores(Address, Address pw){//callback for scores button
	reference_to<win1>(pw).scores();
}
void win1::scores(){//scores function
	win3 test2(Point(0,0),400,600,"High Scores");
	gui_main();
}
void win1::cb_quit(Address, Address pw){//callback for quit button
	reference_to<win1>(pw).quit();
}
void win1::quit(){//quit function
	hide();
}
void win1::cb_qb(Address, Address pw){//callback for quarterback button
	reference_to<win1>(pw).qb();
}

//drawing buttons, rectangles
void win1::qb(){//quarterback button
	hide();
	gameboard test(Point(0,0),1024,675,"Johnny Football vs. SEC");
	Vector_ref<Rectangle> rec;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			rec.push_back(new Rectangle(Point(j*80+150,i*80),80,80));
			Button *button = new Button(Point(j*80+150, i*80),80,80,"",cb_click);
			if( (j+i)%2==0){
				rec[rec.size()-1].set_fill_color(Color::red);
				
				
				test.attach(*button);
			}
			else{
				rec[rec.size()-1].set_fill_color(Color::black);
				test.attach(*button);
			}

			test.attach(rec[rec.size()-1]);
			test.attach(count);
			test.attach(score);
			test.attach(score1);
		}
	}
	win2 test1(Point(0,0),300,100,"");
	gui_main();
}
void win1::cb_lm(Address, Address pw){//callback for linemen button
	reference_to<win1>(pw).lm();
}

//drawing buttons, rectangles
void win1::lm(){//linemen function
	hide();
	gameboard test(Point(0,0),1024,675,"Johnny Football vs. SEC");
	Vector_ref<Rectangle> rec;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			rec.push_back(new Rectangle(Point(i*80+150,j*80),80,80));
			Button* button = new Button(Point(i*80+150,j*80),80,80,"",cb_click2);
			
			if( (j+i)%2==0){
				test.attach(*button);
				rec[rec.size()-1].set_fill_color(Color::red);
			}
			else{
				test.attach(*button);
				rec[rec.size()-1].set_fill_color(Color::black);
			}
			
			Button* button4 = new Button(Point(800,250),125,40,"Start",cb_click4);
			test.attach(*button4);
			test.attach(rec[rec.size()-1]);
			test.attach(count);
			test.attach(score);
		}
	}
	win2 test1(Point(0,0),300,100,"");
	gui_main();
}
void win1::cb_back(Address, Address pw){//callback for back button
	reference_to<win1>(pw).back();
}
void win1::back(){//back function
	detach(bg1);
	detach(QB_button);
	detach(LM_button);
	detach(back_button);
	attach(bg);
	attach(play_button);
	attach(load_button);
	attach(scores_button);
	attach(quit_button);
	attach(rules_button);
}
void win1::cb_back2(Address, Address pw){//callback for second back button
	reference_to<win1>(pw).back2();
}
void win1:: back2(){//second back button
	detach(bgrules);
	detach(back2_button);
	attach(bg);
	attach(play_button);
	attach(load_button);
	attach(scores_button);
	attach(quit_button);
	attach(rules_button);
}
void win1::cb_click4(Address address, Address pw){//callback for start button on linemen
	Fl_Widget* widget = static_cast<Fl_Widget*>(address);
	reference_to<win1>(pw).start_game();
}
void win1:: cb_click(Address address,Address pw){//callback for game buttons on quarterback
	Fl_Widget* widget = static_cast<Fl_Widget*>(address);
	int c = widget->x() / widget->w();
	int r = widget->y() / widget->h();
	cout<<"c-position"<<c-1<<endl;
	cout<<"r-position"<<r<<endl;
	reference_to<win1>(pw).set_move(c-1,r);
	//cout<<c<<r;
}
void win1::cb_click2(Address address, Address pw){//callback for game buttons on linemen
	Fl_Widget* widget = static_cast<Fl_Widget*>(address);
	int c = widget->x() / widget->w();
	int r = widget->y() / widget->h();
	if(rks==1)
	{
		if(save_rks!=c-1)
		{
			reference_to<win1>(pw).set_move2(c-1,r);
			rks=0;
		}
	}
	else
	{
		rks=1;
		make_x= r;
		make_y=c-1;
		save_rks= c-1;
	}
}
void win1:: start_game()//start game fucntion which starts game on linemen
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
				board2[i][j]='-';
		}
	}
	
	board2[0][0] = a;
	al.push_back(new Circle(Point(0*80+190,0*80+40),22));
	al[al.size()-1].set_style(Line_style(Line_style::solid,20));
	
	al[al.size()-1].set_color(Color::yellow);
	attach(al[al.size()-1]);
	board2[0][2] = b;
	bl.push_back(new Circle(Point(2*80+190,0*80+40),22));
	bl[bl.size()-1].set_style(Line_style(Line_style::solid,20));
	
	bl[bl.size()-1].set_color(Color::yellow);
	attach(bl[bl.size()-1]);
	board2[0][4] = 'C';
	cl.push_back(new Circle(Point(4*80+190,0*80+40),22));
	cl[cl.size()-1].set_style(Line_style(Line_style::solid,20));
	
	cl[cl.size()-1].set_color(Color::yellow);
	attach(cl[cl.size()-1]);
	board2[0][6] = d;
	dl.push_back(new Circle(Point(6*80+190,0*80+40),22));
	dl[dl.size()-1].set_style(Line_style(Line_style::solid,20));
	
	dl[dl.size()-1].set_color(Color::yellow);
	attach(dl[dl.size()-1]);
	redraw();
	
	int ran_back= rand() % 6;
	int rk;
	
	if(ran_back%2==1)
	{
		rk=ran_back;
		board2[7][ran_back] = 'X';
	}
	else
	{
		rk=ran_back+1;
		board2[7][ran_back+1] = 'X';
	}
	xl.push_back(new Circle(Point(rk*80+190,7*80+40),22));
	xl[xl.size()-1].set_style(Line_style(Line_style::solid,20));
	
	xl[xl.size()-1].set_color(Color::magenta);
	attach(xl[xl.size()-1]);
	cker=1;
	players=1;
	
	counter++;
	
	ss<< counter;
	prints= ss.str();
	
	tl.push_back(new Text(Point(900,105),prints));
	tl[tl.size()-1].set_font_size(20);
	
	attach(tl[tl.size()-1]);

	

}
bool win1::check2(char board2[n][n], int c1, int k, char plays){//looking for linemen postion on board and check if it is a valid move or not
	char x = 'X';
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(board2[i][j]==plays)
			{
				
			if(plays == a)
			{
				
				
					if(j+1 == k || j-1 == k){
						if(board2[c1][k] == b || board2[c1][k] == c || board2[c1][k] == d || board2[c1][k] == x)
						{
							return false;
						}
						else
						{
							return true;
						}
					
				}
			}
			else if(plays == b)
			{
				
					if(j+1 == k || j-1 == k){
						if(board2[c1][k] == a || board2[c1][k] == c || board2[c1][k] == d || board2[c1][k] == x)
						{
							return false;
						}
						else
						{
							return true;
						}
				}
			}
			else if(plays == c)
			{
				
					if(j+1 == k || j-1 == k){
						if(board2[c1][k] == a || board2[c1][k] == b || board2[c1][k] == d || board2[c1][k] == x)
						{
							return false;
						}
						else
						{
							return true;
						}
					
				}
			}
			else if(plays == d)
			{
				
					if(j+1 == k || j-1 == k){
						if(board2[c1][k] == a || board2[c1][k] == b || board2[c1][k] == c || board2[c1][k] == x)
						{
							return false;
						}
						else
						{
							return true;
						}
					
					}
				}
			}
		}
	}
}
bool win1::check(char board2[n][n], int c1, int k){//looking for quarterbacks position and check if there is a valid move or not
	char x = 'X';

	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(board2[i][j] == x)
			{
			
				cout << board2[i][j];
				cout << i << endl;
				cout << j << endl;
			
				if(i+1 == c1 || i-1 == c1)
				{
					if(j+1 == k || j-1 == k){
						if(board2[c1][k] == a || board2[c1][k] == b || board2[c1][k] == c || board2[c1][k] == d)
						{
							return false;
						}
						else
						{
							board2[i][j]='-';
							return true;
							
							
						}
					}
				}
			}
		}
	}
}

bool win1::check_second(char board2[n][n], int c1, int k){//check for validity move
	char x = 'X';
	
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(board2[i][j] == x)
			{

						if(board2[c1][k] == a || board2[c1][k] == b || board2[c1][k] == c || board2[c1][k] == d)
						{
							return false;
						}
						else
						{
							check_i = i;
							mk = j;
							
							return true;
							
						}
			}
		}
	}
}

bool win1::determine(char board[n][n]){//determining if the game is over
	char x = 'X';
	char a = 'A';
	char b = 'B';
	char c = 'C';
	char d = 'D';
	int aai,bi,ci, di, ax;
	
	
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if (board[i][j]==a)
			{
				aai=i;
			}
			else if (board[i][j]==b)
			{
				bi=i;
			}
			else if (board[i][j]==c)
			{
				ci=i;
			}
			else if (board[i][j]==d)
			{
				di=i;
			}
		}
	}

	
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
		
			if(board[i][j] == x)
			{
					
				ax= i;
						
				if((board[i-1][j+1] == a || board[i-1][j+1] == b || board[i-1][j+1] == c || board[i-1][j+1] == d) && (board[i-1][j-1] == a || board[i-1][j-1] == b || board[i-1][j-1] == c || board[i-1][j-1] == d) && board[7][j] == x)
				{
					wining=1;
					scoring(1);
					
					return true;
				}
				else if((board[i+1][j+1] == a || board[i+1][j+1] == b || board[i+1][j+1] == c || board[i+1][j+1] == d) && (board[i+1][j-1] == a || board[i+1][j-1] == b || board[i+1][j-1] == c || board[i+1][j-1] == d) && (board[i-1][j-1] == a || board[i-1][j-1] == b || board[i-1][j-1] == c || board[i-1][j-1] == d) && (board[i-1][j+1] == a || board[i-1][j+1] == b || board[i-1][j+1] == c || board[i-1][j+1] == d))
				{
					wining=1;
					scoring(1);
					return true;
				}
				else if((board[i][0] == x) && (board[i+1][j+1] == a || board[i+1][j+1] == b || board[i+1][j+1] == c || board[i+1][j+1] == d) && (board[i-1][j+1] == a || board[i-1][j+1] == b || board[i-1][j+1] == c || board[i-1][j+1] == d))
				{
					wining=1;
					scoring(1);
					return true;
				}
				else if((board[i][7] == x) && (board[i+1][j-1] == a || board[i+1][j-1] == b || board[i+1][j-1] == c || board[i+1][j-1] == d) && (board[i-1][j-1] == a || board[i-1][j-1] == b || board[i-1][j-1] == c || board[i-1][j-1] == d))
				{
					wining=1;
					scoring(1);
					return true;
				}
				else if(board[0][j] == x)
				{
					wining=2;
					scoring(3);
					return true;
				}
				else
				{
					//return false;
				}
			}
		}
	}
	
	if( (aai <= ax) || (bi <= ax) || (ci <= ax) || (di <= ax))
	{
		
		return false;
		
	}
	else
	{
		wining=2;
		return true;
	}
}

bool win1:: max_path(char board[n][n],int fin, int finy,int &result )//finds the back moves for quarterbacks
{

	
		if((board[fin][finy+1] == a || board[fin][finy+1]== b || board[fin][finy+1] == c || board[fin][finy+1]==d ) ||  (board[fin][finy-1] == a || board[fin][finy-1]==b || board[fin][finy] == c || board[fin][finy-1]==d ))
	{
		
		//result= +1;
		return true;
	}
		else if((board[fin+1][finy+1] == a || board[fin+1][finy+1]== b || board[fin+1][finy+1] == c || board[fin+1][finy+1]==d ) ||  (board[fin+1][finy-1] == a || board[fin+1][finy-1]==b || board[fin+1][finy] == c || board[fin+1][finy-1]==d ))
		{
		
			return true;
		}

	else
	{
		return false;
	}
}

void win1::set_move2(int c, int r){//move the players on linemen game
	
	final_x= c;
	final_y=r;
	
	
	players4();
	if(roomable==1)
	{
	
		if(!determine(board2))
		{
			game_intial();
			int last_i;
			int last_j;
			find_i(board2, last_i,last_j);
			int findi= last_i;
			int check_j;
			int coutt= last_j;
			last_j= last_j+ palyer_rand;
					cout<<palyer_rand<<" "<<findi<<endl;
			
			
		
		
			
			int rt=findi;
			if(max_path(board2,findi-2,last_j,check_j))
			{
				findi= findi + 2;
				if(last_j+1<=7)
					last_j = coutt+1;
				else
				{
					last_j = coutt-1;
				}
					


				if(findi>=8)
				{
					findi=findi-1;
					last_j= coutt-1;
					
				}

				//rt=findi-1;
				flag=1;
				
				
			}
			else
			{
			
			}
			
			
			if((findi-1) <=7 && (findi-1) > -1 && last_j >-1 && last_j<=7 )
			{
				
				if(check_second(board2,findi-1,last_j) ){ //|| flag==0){
				
			
				board2[check_i][mk]='-';
				board2[findi-1][last_j] = 'X';
				
				detach(xl[xl.size()-1]);
				redraw();
				
				xl.push_back(new Circle(Point((last_j)*80+190,(findi-1)*80+40),22));
				xl[xl.size()-1].set_style(Line_style(Line_style::solid,20));
				
				xl[xl.size()-1].set_color(Color::magenta);
				attach(xl[xl.size()-1]);
					roomable=0;
				//players4();
				
		          }
			}
			else
			{
				
				set_move2(c,r);
			}
			
			
		}
	

	}

}

void win1:: game_intial()//random moves
	{
		int sks;
		palyer_rand = (rand() % 2) + 1;
		
		if(palyer_rand==2)
			sks=-1;
		else
			sks=1;
		
		palyer_rand= sks;
		
	
	}

	
	int win1:: find_i(char board[n][n], int &m, int &l)//looking for the position of i
	{
		char x = 'X';
		
		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				if(board[i][j] == x)
				{
					m=i;
					l=j;
				
					return i;
				}
			}
		}
			
		
	}
void win1:: findplay (char board2[n][n],int i, int j)//finding the players
{

	if(board2[i][j]== a || board2[i][j]== b || board2[i][j]== c || board2[i][j]== d )
	{
		plays = board2[i][j];
	}
}
void win1::players4()//choose players from linemens
{

	
	findplay(board2,make_x,make_y);
	
	choseplayer(board2,make_x,make_y,plays);
	
	//cout<<"chose player"<<rk<<"   "<<ck<<" "<<plays<<endl;
	
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			cout<<board2[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	int cj=final_y;
	int rk= final_x;

	if(check2(board2,cj, rk, plays))
	{
		ai=board2[make_x][make_y];
		
		
	
		
		
		
		if((cj<8) && (cj>-1) && (rk<=7) )
		{
			
			board2[make_x][make_y]='-';
			board2[cj][rk] = plays;
			
			if(ai==a)
			{
				detach(al[al.size()-1]);
				redraw();
				al.push_back(new Circle(Point(rk*80+190,(cj)*80+40),22));
				al[al.size()-1].set_style(Line_style(Line_style::solid,20));
				
				al[al.size()-1].set_color(Color::yellow);
				attach(al[al.size()-1]);
				redraw();
				roomable=1;
				
			}
			else if (ai==b)
			{
				detach(bl[bl.size()-1]);
				redraw();
				bl.push_back(new Circle(Point(rk*80+190,(cj)*80+40),22));
				bl[bl.size()-1].set_style(Line_style(Line_style::solid,20));
				
				bl[bl.size()-1].set_color(Color::yellow);
				attach(bl[bl.size()-1]);
				redraw();
					roomable=1;
			}
			else if (ai==c)
			{
				detach(cl[cl.size()-1]);
				redraw();
				
				cl.push_back(new Circle(Point(rk*80+190,(cj)*80+40),22));
				cl[cl.size()-1].set_style(Line_style(Line_style::solid,20));
				
				cl[cl.size()-1].set_color(Color::yellow);
				attach(cl[cl.size()-1]);
				redraw();
					roomable=1;
			}
			else if (ai==d)
			{
				detach(dl[dl.size()-1]);
				redraw();
				
				dl.push_back(new Circle(Point(rk*80+190,(cj)*80+40),22));
				dl[dl.size()-1].set_style(Line_style(Line_style::solid,20));
				
				dl[dl.size()-1].set_color(Color::yellow);
				attach(dl[dl.size()-1]);
				redraw();
					roomable=1;
			}
			
			counter++;
			stringstream s5;
			s5<<"";
			s5<< counter;
			prints="";
			prints= s5.str();
			
			detach(tl[tl.size()-1]);
			//	redraw();
			tl.push_back(new Text(Point(900,105),prints));
			tl[tl.size()-1].set_font_size(20);
			attach(tl[tl.size()-1]);

			
	
		}
		
		
		if(determine(board2))
		{
			if(wining==1)
			{
				
				write_file();
				
				t6.push_back(new Text(Point(810,50),"Lineman Won!!"));
				t6[t6.size()-1].set_font_size(20);
				attach(t6[t6.size()-1]);
				ss1<< read_score;
				string sc= ss1.str();
				t6.push_back(new Text(Point(900,145),sc));
				t6[t6.size()-1].set_font_size(20);
				attach(t6[t6.size()-1]);
				
				
				
				
			}
			else
			{
				write_file();
				t6.push_back(new Text(Point(810,50),"Quarterback Won!!"));
				t6[t6.size()-1].set_font_size(20);
				attach(t6[t6.size()-1]);
				ss1<< read_score;
				string sc= ss1.str();
				t6.push_back(new Text(Point(900,145),sc));
				t6[t6.size()-1].set_font_size(20);
				attach(t6[t6.size()-1]);
				
				
			}
		}
		


		
		
	}
	else{
		
		//players3();
	}
	
}
	//-==========================================================
void win1::set_move(int c, int r){//move the players on quarterback game
	if(kil==1)
	{
		board2[0][0] = a;
		al.push_back(new Circle(Point(0*80+190,0*80+40),22));
		al[al.size()-1].set_style(Line_style(Line_style::solid,20));
		
		al[al.size()-1].set_color(Color::yellow);
		attach(al[al.size()-1]);
		board2[0][2] = b;
		bl.push_back(new Circle(Point(2*80+190,0*80+40),22));
		bl[bl.size()-1].set_style(Line_style(Line_style::solid,20));
		
		bl[bl.size()-1].set_color(Color::yellow);
		attach(bl[bl.size()-1]);
		board2[0][4] = 'C';
		cl.push_back(new Circle(Point(4*80+190,0*80+40),22));
		cl[cl.size()-1].set_style(Line_style(Line_style::solid,20));
		
		cl[cl.size()-1].set_color(Color::yellow);
		attach(cl[cl.size()-1]);
		board2[0][6] = d;
		dl.push_back(new Circle(Point(6*80+190,0*80+40),22));
		dl[dl.size()-1].set_style(Line_style(Line_style::solid,20));
		
		dl[dl.size()-1].set_color(Color::yellow);
		attach(dl[dl.size()-1]);
		redraw();
		if(r==7)
		{
			if(c == 1 || c == 3 || c == 5 || c == 7){
				board2[r][c] = 'X';
			
				xl.push_back(new Circle(Point(c*80+190,r*80+40),22));
				xl[xl.size()-1].set_style(Line_style(Line_style::solid,20));
		
				xl[xl.size()-1].set_color(Color::magenta);
				attach(xl[xl.size()-1]);
				cker=1;
				players=1;
				counter++;
				
				ss<< counter;
				prints= ss.str();
			
				//redraw();
				tl.push_back(new Text(Point(900,105),prints));
				//tl[tl.size()-1].set_font(Font::times_bold);
				tl[tl.size()-1].set_font_size(20);
				
				//	count.set_font(Font::times_bold);
				//	count.set_font_size(20);
				attach(tl[tl.size()-1]);
			}
		}
	}
	else
	{
		if(!determine(board2))
		{
			if(wining==1)
				cout<<"linemen won!!!";
			else if(wining==2)
				cout<<"quarterback won";

			
		if(check(board2,r,c)){
			int rt=r;
			
			
			board2[r][c] = 'X';
			detach(xl[xl.size()-1]);
			redraw();
		
			xl.push_back(new Circle(Point(c*80+190,r*80+40),22));
			xl[xl.size()-1].set_style(Line_style(Line_style::solid,20));
			   
			xl[xl.size()-1].set_color(Color::magenta);
			attach(xl[xl.size()-1]);
			players3();
		}
		}
		else
		{
			if(wining==1)
			{
				t6.push_back(new Text(Point(810,50),"Lineman Won!!"));
				t6[t6.size()-1].set_font_size(20);
				attach(t6[t6.size()-1]);
				ss1<< read_score;
				string sc= ss1.str();
								t6.push_back(new Text(Point(900,145),sc));
				t6[t6.size()-1].set_font_size(20);
				attach(t6[t6.size()-1]);
				
				write_file();
				cout<<"linemen won!!!";
			}
			else
			{
				t6.push_back(new Text(Point(810,50),"Quarterback won!!"));
				t6[t6.size()-1].set_font_size(20);
				attach(t6[t6.size()-1]);
				write_file();
				ss1<< read_score;
				string sc= ss1.str();
				t6.push_back(new Text(Point(900,145),sc));
				t6[t6.size()-1].set_font_size(20);
				attach(t6[t6.size()-1]);

				cout<<"quarterback won";
			}

		}
	}
	if(cker==1)
	{
		kil++;
		players+=1;
	}
}
	void win1::player_chose()
	{
		
	}
void win1:: choseplayer(char board2[n][n],int &irn,int &jrn, char a )//choose players
{
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			if(board2[i][j]==a)
			{
				irn=i;
				jrn=j;
				
				break;

			}
				
	
}
void win1::players3()//linemens artifical intelligence
{
		initialize();
	

	if(rand_oper==1)
	{
		plays='A';
	}
	else if(rand_oper==2)
	{
		plays='B';
		
	}
	else if(rand_oper==3)
	{
		plays='C';
	}
	else if(rand_oper==4)
	{
		plays='D';
	}
	
	
	choseplayer(board2,rk,ck,plays);
	
	int cj=rand_j +ck;
	if(check2(board2,rk+1, cj, plays))
	{
		ai=board2[rk][ck];
	
	cout<<"i rk "<<rk+1<<" "<<"ck j "<<cj<<endl;
	
		if((cj<8) && (cj>-1) && (rk+1<=7) )
		{
			board2[rk][ck]='-';
			board2[rk+1][cj] = plays;
		
		if(ai==a)
		{
			detach(al[al.size()-1]);
			redraw();
			al.push_back(new Circle(Point(cj*80+190,(rk+1)*80+40),22));
			al[al.size()-1].set_style(Line_style(Line_style::solid,20));
			
			al[al.size()-1].set_color(Color::yellow);
			attach(al[al.size()-1]);
			redraw();
		
		}
		else if (ai==b)
		{
			detach(bl[bl.size()-1]);
			redraw();
			bl.push_back(new Circle(Point(cj*80+190,(rk+1)*80+40),22));
			bl[bl.size()-1].set_style(Line_style(Line_style::solid,20));
			
			bl[bl.size()-1].set_color(Color::yellow);
			attach(bl[bl.size()-1]);
			redraw();
			
		}
		else if (ai==c)
		{
			detach(cl[cl.size()-1]);
			redraw();
			
			cl.push_back(new Circle(Point(cj*80+190,(rk+1)*80+40),22));
			cl[cl.size()-1].set_style(Line_style(Line_style::solid,20));
			
			cl[cl.size()-1].set_color(Color::yellow);
			attach(cl[cl.size()-1]);
			redraw();
		}
		else if (ai==d)
		{
			detach(dl[dl.size()-1]);
			redraw();
			
			dl.push_back(new Circle(Point(cj*80+190,(rk+1)*80+40),22));
			dl[dl.size()-1].set_style(Line_style(Line_style::solid,20));
			
			dl[dl.size()-1].set_color(Color::yellow);
			attach(dl[dl.size()-1]);
			redraw();
		}
		
		}
		else
		{
			players3();
		}
		counter++;
		stringstream s3;
		s3<<"";
		s3<< counter;
		prints="";
		prints= s3.str();
		
		detach(tl[tl.size()-1]);

		tl.push_back(new Text(Point(900,105),prints));

		tl[tl.size()-1].set_font_size(20);

		attach(tl[tl.size()-1]);
		
		
		if(determine(board2))
		{
			if(wining==1)
			{
			
				write_file();
				
				t6.push_back(new Text(Point(810,50),"Line man Won!!"));
				t6[t6.size()-1].set_font_size(20);
				attach(t6[t6.size()-1]);
				ss1<< read_score;
				string sc= ss1.str();
				t6.push_back(new Text(Point(900,145),sc));
				t6[t6.size()-1].set_font_size(20);
				attach(t6[t6.size()-1]);

				
				
				
			}
			else
			{
				write_file();
				t6.push_back(new Text(Point(810,50),"Quater man Won!!"));
				t6[t6.size()-1].set_font_size(20);
				attach(t6[t6.size()-1]);
				ss1<< read_score;
				string sc= ss1.str();
				t6.push_back(new Text(Point(900,145),sc));
				t6[t6.size()-1].set_font_size(20);
				attach(t6[t6.size()-1]);

					
			}
		}
	
		
	}
	else{
	
		players3();
	}

}
void win1::initialize(){//random moves for linemens
	int sks;
	rand_oper=(rand() % 4 )+ 1;
	rand_j= (rand() % 2) + 1;
	if(rand_j==2)
		sks=-1;
	else
		sks=1;
	
		rand_j= sks;
	
	if (rand_oper==1 && sks==-1)
		rand_j=sks+2;
		
}
void win1::scoring(int a){//totals the scores
	if(a == 1){
		read_score *= 2;
	}
	else if(a ==2){
		read_score *= 3;
	}
	else if(a==3){
		read_score = 100;
	}
}
void win1::read_file(){//read the file
	ifstream filename;
	string read;
	filename.open("scores.txt");
	if(filename.is_open()){
			getline(filename, read);
			cout <<"READ: "<< read << endl;
		}
}
void win1::write_file(){//write the file
	ofstream filename;
	//filename.open("scores.txt");
	filename.open ("scores.txt", ios::out | ios::app | ios::binary); 
	filename<<player_name <<endl;
	filename << read_score << endl;
	filename.close();
}
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
int main()
{	
	win1 test(Point(20,20),1024,675,"Johnny Football vs. SEC");// this is main menu window to call main window.
	gui_main();
}
