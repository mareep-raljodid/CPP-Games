/****************************************************************************
 *
 * Project Title:
 * COMMANDO 2.0
 * Description: A game where player starts in an unknown map. Searches for three bombs and deactivate them to aquire IDs. And lastly deactivates the main bomb to win the game.
 *
 *
 * Developers:
 * - Rajdeep Bandopadhyay - bandoprp@mail.uc.edu
 *
 *
 * Help Received:
 * [From NOBODY]
 *
 *
 *
 * Special Instructions:
 * - How to compile
 * - How to run it
 *
 *
 *
 * 
 ****************************************************************************/
#include <iostream>
#include <cstring>
#include <cctype>
#include <math.h>
#include <iomanip>
#include <chrono>
#include <time.h>


using namespace std;

void
print_banner ()
{
  cout <<
    "--------------------------------------------------------------------------------------------------------------------------------------------------------------"
    << endl;
  cout <<
    ".##......##.########.##........######...#######..##.....##.########....########..#######......................................................................"
    << endl;
  cout <<
    ".##..##..##.##.......##.......##....##.##.....##.###...###.##.............##....##.....##....................................................................."
    << endl;
  cout <<
    ".##..##..##.##.......##.......##.......##.....##.####.####.##.............##....##.....##....................................................................."
    << endl;
  cout <<
    ".##..##..##.######...##.......##.......##.....##.##.###.##.######.........##....##.....##....................................................................."
    << endl;
  cout <<
    ".##..##..##.##.......##.......##.......##.....##.##.....##.##.............##....##.....##....................................................................."
    << endl;
  cout <<
    ".##..##..##.##.......##.......##....##.##.....##.##.....##.##.............##....##.....##....................................................................."
    << endl;
  cout <<
    "..###..###..########.########..######...#######..##.....##.########.......##.....#######......................................................................"
    << endl;
  cout <<
    ".............................................................................................................................................................."
    << endl;
  cout <<
    "..######...#######..##.....##.##.....##....###....##....##.########...#######............#######........#####............########..########.########....###..."
    << endl;
  cout <<
    ".##....##.##.....##.###...###.###...###...##.##...###...##.##.....##.##.....##..........##.....##......##...##...........##.....##.##..........##......##.##.."
    << endl;
  cout <<
    ".##.......##.....##.####.####.####.####..##...##..####..##.##.....##.##.....##.................##.....##.....##..........##.....##.##..........##.....##...##."
    << endl;
  cout <<
    ".##.......##.....##.##.###.##.##.###.##.##.....##.##.##.##.##.....##.##.....##...........#######......##.....##..........########..######......##....##.....##"
    << endl;
  cout <<
    ".##.......##.....##.##.....##.##.....##.#########.##..####.##.....##.##.....##..........##............##.....##..........##.....##.##..........##....#########"
    << endl;
  cout <<
    ".##....##.##.....##.##.....##.##.....##.##.....##.##...###.##.....##.##.....##..........##........###..##...##...........##.....##.##..........##....##.....##"
    << endl;
  cout <<
    "..######...#######..##.....##.##.....##.##.....##.##....##.########...#######...........#########.###...#####............########..########....##....##.....##"
    << endl;
  cout <<
    "--------------------------------------------------------------------------------------------------------------------------------------------------------------"
    << endl;
}

int
msleep (unsigned long milisec)
{
  struct timespec req = { 0 };
  time_t sec = (int) (milisec / 1000);
  milisec = milisec - (sec * 1000);
  req.tv_sec = sec;
  req.tv_nsec = milisec * 1000000L;
  while (nanosleep (&req, &req) == -1)
    continue;
  return 1;
}

void
game_over (int a)
{
  if (a == 1)
    cout << "Congratulations! You won!" << endl;
  if (a == 2)
    cout << "YOU LOST. GAME OVER." << endl;
  if (a == 3)
    cout << "You Exitted." << endl;
}

//-------Player's Choices----------
int
install (int a)
{
  if (a == 3)
    cout << "You successfully installed the camera." << endl;
  else
    cout << "Nothing to install." << endl;
}

void
search (int pos)
{
  char gg, hj, coco;
  int hh;
  if (pos == 0)
    {
      cout << "After getting the objectives, you scanned the open grounds.."
	<< endl;
      cout <<
	"And not so surprisingly, you found a bomb which was right on the way to forest."
	<< endl;
      cout << "Ofcourse now you need to deactivate it..." << endl;
      cout << "The bonb has Identification Number of 1377.";
    }
  if (pos == 1)
    {
      cout << "You arrived in the forest, you started the scan.." << endl;
      msleep (2000);
      cout <<
	"There are lot of trees and wild life around, the scan might take some more time.."
	<< endl;
      cout << "still scanning.." << endl;
      msleep (4000);
      cout << "..scanning complete!" << endl;
      cout <<
	"There is a bomb in a distance and seems like some sort of wild animal, probably a monkey, is hitting it with something.."
	<< endl;
      cout <<
	"You need to hurry up, or else the monkey might cause some problem."
	<< endl;
      cout << "You throw rock at the monkey and scare it off.." << endl;
      cout <<
	"You go upclose, and you see the bomb has Identification Number of 1297."
	<< endl;
    }
  if (pos == 2)
    {
      cout << "You go in the village, there are two houses.." << endl;
      cout <<
	"You scan and come to realize that you need to go in to get in range of a bomb [if there is one], although you can see that there are only 2 houses in total."
	<< endl;
      cout <<
	"Which one do you want to go in first? Type 1 to go inside the smaller one or  2 to go inside the huge one."
	<< endl;
      cin >> hh;
      if (hh == 1)
	{
	  cout << "You go in, you started scanning..." << endl;
	  msleep (2000);
	  cout <<
	    "Scanning complete, there is a bomb right infront of you, and it has Identification Number of 8983."
	    << endl;
	  cout << "Do you want to search the other house? (Y/N)." << endl;
	  cin >> gg;
	  if (gg == 'Y')
	    goto jgh;
	}
      else if (hh == 2)
	{
	jgh:
	  cout << "You go in, you started scanning the other house..." <<
	    endl;
	  msleep (2000);
	  cout << "Its taking some time..." << endl;
	  msleep (8000);
	  cout << "It took too long, but lucklily nothing was found." << endl;
	}
      else
	{
	  cout << "Invalid choice, try again." << endl;
	}
    }
  if (pos == 3)
    {
      cout << "You scan the lake, and there is a bomb at the bank." << endl;
      cout <<
	"You go upclose, but the tag showing the Identification Number was rusted, you tried very hard to read and only thing you were able to read was 583_ the last number was not readable."
	<< endl;
      cout <<
	"You look around and see something that looks similar to a camera on a tree nearby..."
	<< endl;
      cout << "You go upclose... " << endl;
      msleep (2000);
      cout <<
	"Your equipments warn you of some sort of explosive device, but you happen to have a signal jammer on your equipment.."
	<< endl;
      cout << "Do you want to use it? (Y/N)" << endl;
      cin >> hj;
      if (hj == 'Y')
	{
	  cout << "You turn it on and go to investigate it..." << endl;
	  msleep (800);
	  cout <<
	    "Using your equipments you see the recorded pictures on it..and yo see the bomb and it had 5837 as its Identification Number!!"
	    << endl;
	  cout << "You can take that camera, it can be used later." << endl;
	}
      else
	{
	  cout <<
	    "You go without turning the jammer on, the camera on the tree starts beeping..."
	    << endl;
	  msleep (2000);
	  cout << "Do you want to closer to investigate? (Y/N)" << endl;
	  cin >> coco;
	  if (coco == 'Y')
	    {
	      cout <<
		"The cmaera had a detonator.. and it was contolled by the enemies."
		<< endl;
	      cout << "...and it blasted." << endl;
	      game_over (2);
	    }
	}
    }
}

int
forest ()
{
  cout <<
    "You are in the forest...it was the most vivid forest you have ever seen, the sound, the smell..."
    << endl;
  cout <<
    "You hear branches creaking, feet shuffling through detritus, squirrels chattering, leaves rustling, wind whistling around trunks/disturbing the leaves, birds singing, insects humming/ churring, rustle of animals rooting in underbrush, scrabbling of lizards on tree bark, limbs.."
    << endl;
  cout << "What do you want to do?" << endl;
  return 1;
}

int
lake ()
{
  cout <<
    "You are at the lake...you can smell the wet grounds, water rustling against the shore and touching your shoes..."
    << endl;
  cout <<
    "The small path widened into a multicolored beach with every size of rock - from boulders big enough to sit on, to grains that got stuck between your toes. Beyond was a flat lake, the far shore a thin line in the distance growing into a sheer cliff face. In the black watery mirror was only the constellations, starlight so old and young. Wooden boats sent ripples to subside in the deeper water, each moored to the protruding pontoon. As they approached the waterline, he bent down and skimmed a rock - the splash loud in the otherwise silent night and the ripples fading slowly from the poorly thrown pebble. Coniferous trees cast shadows across the shoreline, like the soft blanket he hid under as a child, always feeling safer unseen....."
    << endl;
  cout << "What do you want to do?" << endl;
  return 2;
}

int
village ()
{
  cout << "You are in Village.." << endl;
  cout << "What do you want to do?" << endl;
  return 3;
}

int
get (int pos)
{
  if (pos == 3)
    {
      cout << "You aquired an explosive camera!" << endl;
      return 1;
    }
  else
    {
      cout << "There is nothing to aquire!" << endl;
      return 0;
    }
}

int
deactivate (int q)
{
  int a = 0;
  if (q == 1337)
    a += 21;
  if (q == 1297)
    a += 32;
  if (q == 5837)
    a += 47;
  return a;

}

int
nukey (int x)
{
  int c = 0;
  if (x == 5837)
    {
      cout << "That worked!!" << endl;
      game_over (1);
      return 44;
    }
  else
    {
      cout << "One more try to go!" << endl;
      cin >> x;
      if (x == 5837)
	{
	  cout << "Phew..! That worked!" << endl;
	  game_over (1);
	  return 44;
	}
      else
	game_over (2);
      return 44;
    }
}

void
exit ()
{
  game_over (3);
  exit (0);
}


int
grounds ()
{
  char d;
  string g;
  cout << "You are at the open grounds near your plane.." << endl;
  cout << "You get a radiation readings from your plane..." << endl;
  cout << "Something is fishy..Do you want to scan the plane? (y/n)" << endl;
  cin >> d;
  if (d == 'y')
    {
      cout << "You start scanning..." << endl;
      msleep (6000);
      cout <<
	"Scanning is complete... and you find the nuclear bomb in your plane!!!!"
	<< endl;
      cout << "Do something.." << endl;
      cin >> g;
    }
  else
    {
      cout << "The nuclear bomb was in your plane..it exploded." << endl;
      game_over (2);
    }
  return 0;

}

int
get_pos (string a)
{
  if (a == "grounds")
    return 0;
  if (a == "forest")
    return 1;
  if (a == "lake")
    return 2;
  if (a == "village")
    return 3;
}

void
display_help (int pos = 0)
{
  cout << endl;
  cout <<
    "You work for NEBULA, a secret force that controls the world and is responsible for survival of the human altogether."
    << endl;
  cout <<
    "You were assigned a list of objectives by the counter terrorism department. Failing to complete the job could risk the whole humanity."
    << endl;
  cout <<
    "A group of people are trying to start a WORLD WAR III by blasting a nucluear explosive in a certain country and frame another country to start a war. "
    << endl;
  cout <<
    "--------------------------------------------------------------------------------------------------------------------------------------------------------------"
    << endl;
  msleep (1000);
  cout << "Your objectives are: " << endl;
  msleep (1000);
  cout <<
    "     <>Find three C4 bombs that are used as detonator for the main bomb alternatively."
    << endl;
  msleep (1000);
  cout <<
    "     <>Aquire the keys from the all three C4 bombs, and locate the nuclear bomb."
    << endl;
  msleep (1000);
  cout <<
    "     <>Try all the three aquired keys to deactivate the main nuclear bomb."
    << endl;
  msleep (1000);
  cout << "     <>Find fuel for your plane to flee back to the safe zone." <<
    endl;
  msleep (1000);
  cout << "     <>Kill anyone who sees or comes to know about you." << endl;
  msleep (1000);
  cout <<
    "--------------------------------------------------------------------------------------------------------------------------------------------------------------"
    << endl;
  cout <<
    "                                                                        HELP MENU:                                                                            "
    << endl;
  cout <<
    "--------------------------------------------------------------------------------------------------------------------------------------------------------------"
    << endl;
  msleep (1000);
  cout << "You can type the following commands to play the game:" << endl;
  msleep (500);
  cout << "     <>help: to display this help menu." << endl;
  msleep (500);
  cout <<
    "     <>search: to search the area [you are currently in] with your search equipment."
    << endl;
  msleep (500);
  cout <<
    "     <>grounds: to go in the direction of the open grounds [your starting point]."
    << endl;
  msleep (500);
  cout << "     <>forest: to go in the direction of forest." << endl;
  msleep (500);
  cout << "     <>lake: to go in the direction of lake." << endl;
  msleep (500);
  cout << "     <>village: to go in the direction of village." << endl;
  msleep (500);
  cout << "     <>get: to aquire key or get something." << endl;
  msleep (500);
  cout << "     <>install: to install an equipments." << endl;
  msleep (500);
  cout << "     <>deactivate: to deactivate a bomb." << endl;
  msleep (500);
  cout <<
    "     <>nukey: to be used at last, when you have all 3 keys, to deactivate the nuclear explosive."
    << endl;
  msleep (500);
  cout << "     <>exit: to give up and exit the game." << endl;
  msleep (500);
  cout <<
    "Below is the map below, showing the placement of certain places and yourself."
    << endl;
  cout << "Connecting to GPS..." << endl;;
  cout << "" << endl;;
  msleep (4000);
  cout << "...CONNECTED!" << endl;;
  msleep (500);
  cout << "HERE IS THE MAP:" << endl;
  if (pos == 0)
    {
      cout << "|::::::::::::::::::---------------------------|" << endl;
      cout << "|::::::::::::::::::----------...--------------|" << endl;
      cout << "|:::FOREST:::::::::--------.     .------------|" << endl;
      cout << "|::::::::::::::::::------.         .----------|" << endl;
      cout << "|::::::::::::::::::-----.   LAKE    .---------|" << endl;
      cout << "|::::::::::::::::::------.         .----------|" << endl;
      cout << "|-------------------------.       .-----------|" << endl;
      cout << "|---------------------------....--------------|" << endl;
      cout << "|---------------------------------------------|" << endl;
      cout << "|---(000)--------***********************------|" << endl;
      cout << "|---(000)--------*******VILLAGE*********------|" << endl;
      cout << "|----|-|-YOUR----***********************------|" << endl;
      cout << "|----|.|-PLANE---***********************------|" << endl;
      cout << "|---<YOU>-------------------------------------|" << endl;
    }
  if (pos == 1)
    {
      cout << "|::::::::::::::::::---------------------------|" << endl;
      cout << "|::::::::::::::::::----------...--------------|" << endl;
      cout << "|:::FOREST:::::::::--------.     .------------|" << endl;
      cout << "|:::<YOU>::::::::::------.         .----------|" << endl;
      cout << "|::::::::::::::::::-----.   LAKE    .---------|" << endl;
      cout << "|::::::::::::::::::------.         .----------|" << endl;
      cout << "|-------------------------.       .-----------|" << endl;
      cout << "|---------------------------....--------------|" << endl;
      cout << "|---------------------------------------------|" << endl;
      cout << "|---(000)--------***********************------|" << endl;
      cout << "|---(000)--------*******VILLAGE*********------|" << endl;
      cout << "|----|-|-YOUR----***********************------|" << endl;
      cout << "|----|.|-PLANE---***********************------|" << endl;
      cout << "|---------------------------------------------|" << endl;
    }
  if (pos == 2)
    {
      cout << "|::::::::::::::::::---------------------------|" << endl;
      cout << "|::::::::::::::::::----------...--------------|" << endl;
      cout << "|:::FOREST:::::::::--------.     .------------|" << endl;
      cout << "|::::::::::::::::::------.  <YOU>  .----------|" << endl;
      cout << "|::::::::::::::::::-----.   LAKE    .---------|" << endl;
      cout << "|::::::::::::::::::------.         .----------|" << endl;
      cout << "|-------------------------.       .-----------|" << endl;
      cout << "|---------------------------....--------------|" << endl;
      cout << "|---------------------------------------------|" << endl;
      cout << "|---(000)--------***********************------|" << endl;
      cout << "|---(000)--------*******VILLAGE*********------|" << endl;
      cout << "|----|-|-YOUR----***********************------|" << endl;
      cout << "|----|.|-PLANE---***********************------|" << endl;
      cout << "|---------------------------------------------|" << endl;
    }
  if (pos == 3)
    {
      cout << "|::::::::::::::::::---------------------------|" << endl;
      cout << "|::::::::::::::::::----------...--------------|" << endl;
      cout << "|:::FOREST:::::::::--------.     .------------|" << endl;
      cout << "|::::::::::::::::::------.         .----------|" << endl;
      cout << "|::::::::::::::::::-----.   LAKE    .---------|" << endl;
      cout << "|::::::::::::::::::------.         .----------|" << endl;
      cout << "|-------------------------.       .-----------|" << endl;
      cout << "|---------------------------....--------------|" << endl;
      cout << "|---------------------------------------------|" << endl;
      cout << "|---(000)--------***********************------|" << endl;
      cout << "|---(000)--------*******VILLAGE*********------|" << endl;
      cout << "|----|-|-YOUR----********<YOU>**********------|" << endl;
      cout << "|----|.|-PLANE---***********************------|" << endl;
      cout << "|---------------------------------------------|" << endl;
    }

}

int
input (string a, int pos)
{
  if (a == "help")
    {
      display_help (pos);;
    }
  if (a == "search")
    {
      search (pos);
    }
  if (a == "grounds")
    {
      if (pos == 0)
	cout << "You are already there!" << endl;
      else
	forest ();
    }
  if (a == "lake")
    {
      if (pos == 2)
	cout << "You are already there!" << endl;
      else
	lake ();
    }
  if (a == "village")
    {
      if (pos == 3)
	cout << "You are already there!" << endl;
      else
	village ();
    }
  if (a == "get")
    {
      get (pos);
    }
  if (a == "install")
    {
      install (pos);
    }
  if (a == "deactivate")
    {
      cout << "Input bomb ID: " << endl;
      int id;
      cin >> id;
      deactivate (id);
    }
  if (a == "nukey")
    {
      int htu;
      cout << "Input Bomb ID to check the connection." << endl;
      nukey (htu);
    }
  if (a == "exit")
    {
      exit ();
    }
  if (a == "forest")
    {
      forest ();
    }
  if (a == "village")
    {
      village ();
    }
  else
    {
      cout << "Invalid Input, try again. Use <help> to display the manual." <<
	endl;
    }
}

int
main ()
{
  string player_input;
  int the_cal = 9999;
  print_banner ();
  cout <<
    "You land on an open ground, you see a FOREST and a VILLAGE near by, and a LAKE in a distant."
    << endl;
  cout << endl;
  cout <<
    "Your plane is out of fuel, you take two batteries and put in in your scanning equipment and your GPS sensor. You turn those on..."
    << endl;
  cout << "Your device is booting up...";
  msleep (2000);
  cout << ".." << endl;
  cout << "It's on, and your head quaters is transmitting data..";
  msleep (2000);
  cout << "..." << endl;
  cout << "DONE!" << endl;
  cout << "You see something on your screen, see below: " << endl;
  display_help ();
here:
  cout << "Enter your input: " << endl;
  cin >> player_input;
  int rttyio = get_pos (player_input);
  input (player_input, rttyio);
  goto here;
  cout << "Thank you for playing.";
}
