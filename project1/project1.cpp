/****************************************************************************
 *
 * Project Title:
 * COMMANDO 2.0
 * Description: A game where player starts in an unknown map. Searches for three bombs,
 * and deactivate them to aquire IDs. And lastly deactivates the main bomb to win the game.
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
 * No special compilations instructions.
 *
 * Details on how to play and win the game:
 * 1: Go to grounds first, then scan and deactivate.
 * 2: Got to lake, try deactivating and make sure you use the jammer.
 * 3: Go to village and deactivate the bomb in 1st house.
 *
 * Alternative method [Using nukey]:
 * 1: Go to lake and aquire bomb ID from that bomb by using jammer option.
 * 2: Go back to your plane and use same ID.
 *
 * Ways to loose:
 * 1: Not using the jammer option in the lake area.
 * 2: Putting any key [more than once] other than one found at lake when executing nukey command.
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

/* Function Name: banner
 *
 * Function Description:
 * This function displays intro banner.
 *
 * Parameters:
 * None
 *
 * return value:
 * None, void function.
 */


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

/* Function Name: msleep
 *
 * Function Description:
 * This function creates a delay of provided time.
 *
 * Parameters:
 * The milisec parameter is the amount required delay in miliseconds.
 *
 *
 * return value:
 * 1
 */


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

/* Function Name: game_over
 *
 * Function Description:
 * This function exits game by displaying appropriate message.
 *
 * Parameters:
 * The a parameter is what is checked and message is displayed accordingly.
 * 1: Is winning
 * 2: Is loosing
 * 3: Is exitting
 * return value:
 * None
 */


void
game_over (int a)
{
    if (a == 1)
        cout << "Congratulations! You won!" << endl;
    if (a == 2)
        cout << "YOU LOST. GAME OVER." << endl;
    if (a == 3)
        cout << "You Exitted." << endl;
    
    exit (0);
}

/* Function Name: install
 *
 * Function Description:
 * This function displays if camera is installed.
 *
 * Parameters:
 * The a parameter is the position of player on map.
 *
 *
 * return value:
 * none
 */

int
install (int a)
{
    if (a == 3)
        cout << "You successfully installed the camera." << endl;
    else
        cout << "Nothing to install." << endl;
}

/* Function Name: search
 *
 * Function Description:
 * This function displays appropriate messages when a position on map is searched.
 *
 * Parameters:
 * The pos parameter is the position of player on map.
 *
 *
 * return value:
 * None
 */

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
        cout << "The bomb has Identification Number of 1377.";
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
    if (pos == 3)
    {
        cout << "You go in the village, there are two houses.." << endl;
        cout <<
        "You scan and come to realize that you need to go in to get in range of a bomb [if there is one], although you can see that there are only 2 houses in total."
        << endl;
    pop:
        cout <<
        "Which one do you want to go in first? Type 1 to go inside the smaller one or  2 to go inside the huge one."
        << endl;
        cin >> hh;
        if (hh == 1)
        {
            cout << "You go in, you started scanning..." << endl;
            msleep (2000);
            cout <<
            "Scanning complete, there is a bomb right infront of you, and it has Identification Number of 1297."
            << endl;
        }
        else if (hh == 2)
        {
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
            goto pop;
        }
    }
    if (pos == 2)
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

/* Function Name: forest
 *
 * Function Description:
 * This function describes forest
 *
 * Parameters:
 * None
 *
 * return value:
 * None
 */

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
}

/* Function Name: lake
 *
 * Function Description:
 * This function describes lake
 *
 * Parameters:
 * None
 *
 * return value:
 * None
 */

int
lake ()
{
    cout <<
    "You are at the lake...you can smell the wet grounds, water rustling against the shore and touching your shoes..."
    << endl;
    cout <<
    "The small path widened into a multicolored beach with every size of rock - from boulders big enough to sit on, to grains that got stuck between your toes. Beyond was a flat lake,"
    << endl;
    cout <<
    "the far shore a thin line in the distance growing into a sheer cliff face. In the black watery mirror was only the constellations, starlight so old and young."
    << endl;
    cout <<
    "Wooden boats sent ripples to subside in the deeper water, each moored to the protruding pontoon. As they approached the waterline, he bent down and skimmed a rock - the splash loud in the"
    << endl;
    cout <<
    "otherwise silent night and the ripples fading slowly from the poorly thrown pebble. Coniferous trees cast shadows across the shoreline,"
    << endl;
    cout <<
    "like the soft blanket he hid under as a child, always feeling safer unseen....."
    << endl;
    cout << "What do you want to do?" << endl;
}

/* Function Name: village
 *
 * Function Description:
 * This function describes village
 *
 * Parameters:
 * None
 *
 * return value:
 * None
 */

int
village ()
{
    cout << "You are in Village.." << endl;
    cout << "What do you want to do?" << endl;
}

/* Function Name: get
 *
 * Function Description:
 * This function checks is the player aquired the camera.
 *
 * Parameters:
 * The pos parameter position of player on map
 *
 *
 * return value:
 * Indicates 0 for not aquired due to invalid place or 1 for aquired.
 */

int
get (int pos)
{
    if (pos == 2)
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

/* Function Name: deactivate
 *
 * Function Description:
 * This function indicates if a certain bomb has been deactivated
 *
 * Parameters:
 * The q parameter is the Bomb ID
 *
 *
 * return value:
 * Indicates certain numbers if a certain bomb is deactivated.
 */

int
deactivate (int q)
{
    int a = 0;
    if (q == 1337)
    {
        a += 21;
        cout << "Deactivated Successfully" << endl;
    }
    else if (q == 1297)
    {
        a += 32;
        cout << "Deactivated Successfully" << endl;
    }
    else if (q == 5837)
    {
        a += 47;
        cout << "Deactivated Successfully" << endl;
    }
    else
    {
        cout <<
        "No nearby connections with that ID to deactivate, please try again."
        << endl;
    }
    
    return a;
    
}

/* Function Name: nukey
 *
 * Function Description:
 * This function executes nukey function in game
 *
 * Parameters:
 * The x parameter is Bomb ID
 *
 *
 * return value:
 * None
 */

int
nukey (int x)
{
    int c = 0;
    if (x == 5837)
    {
        cout << "That worked!!" << endl;
        game_over (1);
    }
    else
    {
        cout << "One more try to go!" << endl;
        cin >> x;
        if (x == 5837)
        {
            cout << "Phew..! That worked!" << endl;
            game_over (1);
        }
        else
            game_over (2);
    }
}

/* Function Name: exit
 *
 * Function Description:
 * This function executes the exit option in game
 *
 * Parameters:
 * None
 *
 *
 * return value:
 * None
 */

void
exit ()
{
    game_over (3);
    exit (0);
}

/* Function Name: grounds
 *
 * Function Description:
 * This function places player in the grounds part of map
 *
 * Parameters:
 *
 * None
 *
 * return value:
 * None
 */

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
    }
    else
    {
        cout << "The nuclear bomb was in your plane..it exploded." << endl;
        game_over (2);
    }
}

/* Function Name: get_pos
 *
 * Function Description:
 * This function keeps track of current position of player.
 *
 * Parameters:
 * The a parameter is name of place
 *
 *
 * return value:
 * Indicates position
 */

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

/* Function Name: display_help
 *
 * Function Description:
 * This function displays the full game manual along with current location of player.
 *
 * Parameters:
 * The pos parameter is position of payer.
 *
 *
 * return value:
 * None
 */

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
    "The group call themselves The Keepers, and they planted three C4 bombs and one of them will be used to detonate the main Nuclear BOMB."
    << endl;
    cout <<
    "---------------------------------------------------------------------------------------------------------------------------------------------------------------"
    << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    msleep (1000);
    cout <<
    "You have two protocols as your options, you can follow either one of those: "
    << endl;
    msleep (2000);
    cout << endl;
    cout << endl;
    cout << "<*****> Protocol ONE:" << endl;
    cout << endl;
    msleep (1000);
    cout <<
    "     <>Scavenge through the whole map and, deactivate each and every C4. [Note: There are 3 in total]"
    << endl;
    cout <<
    "       Deactivating all three C4 bombs will stop the detonation of the Nuclear Bomb altogether. "
    << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout <<
    "                -------------------------------------------------------------------------------------------------------------------------------                "
    << endl;
    msleep (2000);
    cout << endl;
    cout << endl;
    cout << "<*****> Protocol TWO:" << endl;
    cout << endl;
    msleep (1000);
    cout <<
    "     <>Scavenge through the whole map find the Nuclear Bomb and note the keys from the C4 bombs. [Note: There are 3 C4 in total]"
    << endl;
    cout <<
    "       You do not need to deactivate the C4, noting down the C4 keys and using them to use your <nukey> function from your equipment will disable the Nuclear bomb."
    << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
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
    cout << "     <>install: to install an equipment." << endl;
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

/* Function Name: input
 *
 * Function Description:
 * This function takes input from player and redirects ti required functions, and displays invalid option meggabe in case of invalid option.
 *
 * Parameters:
 * The a parameter is user input
 * The pos parameter is user position
 *
 * return value:
 * Returns certain integers for certain functions to execute through game function
 */

int
input (string a, int pos)
{
    if (a == "help")
    {
        return 10;
    }
    if (a == "search")
    {
        return 20;
    }
    if (a == "grounds")
    {
        return 30;
    }
    if (a == "lake")
    {
        return 40;
    }
    if (a == "village")
    {
        return 50;
    }
    if (a == "forest")
    {
        return 60;
    }
    if (a == "get")
    {
        return 70;
    }
    if (a == "install")
    {
        return 80;
    }
    if (a == "deactivate")
    {
        return 90;
    }
    if (a == "nukey")
    {
        return 110;
    }
    if (a == "exit")
    {
        exit ();
    }
    else
    {
        cout << "Invalid Input, try again. Use <help> to display the manual." <<
        endl;
    }
}

/* Function Name: game
 *
 * Function Description:
 * This function integrates all the functions defined in this program.
 *
 * Parameters:
 * None
 *
 *
 * return value:
 * None
 */

void
game ()
{
    string player_input;
    int cal = 9999, bmb = 0;
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
    cout << "It's on, and your head quater is transmitting data..";
    msleep (2000);
    cout << "..." << endl;
    cout << "DONE!" << endl;
    cout << "You see something on your screen, see below: " << endl;
    display_help ();
    
    cout << "Where do you want to go first? " << endl;
    cin >> player_input;
    int rttyio = get_pos (player_input);
    cout<<"Write the name of the place one more time to read its description."<<endl;
here:
    cout << "Enter your input: " << endl;
    cin >> player_input;
    cal = input (player_input, rttyio);
    if (cal == 10)
    {
        display_help (rttyio);
    }
    if (cal == 20)
    {
        search (rttyio);
    }
    if (cal == 30)
    {
        rttyio = 0;
        grounds ();
    }
    if (cal == 40)
    {
        rttyio = 2;
        lake ();
    }
    if (cal == 50)
    {
        rttyio = 3;
        village ();
    }
    if (cal == 60)
    {
        rttyio = 1;
        forest ();
    }
    if (cal == 70)
    {
        get (rttyio);
    }
    if (cal == 80)
    {
        install (rttyio);
    }
    if (cal == 90)
    {
        int id;
        cout << "Input bomb ID: " << endl;
        cin >> id;
        bmb += deactivate (id);
        if (bmb == 100)
            cout <<
            "You have deactivated all the bombs that could have been a detonator for the Nuclear Bomb,\n at this point it dosen't matter if you find or deactivate the Nuclear Bomb\n because it cannot be Exploded anymore!! Rejoice!!"
            << endl;
    }
    if (cal == 110)
    {
        int htu;
        cout << "Input Bomb ID to check the connection: ";
        cin >> htu;
        nukey (htu);
    }
    goto here;
}

/* Function Name: main
 *
 * Function Description:
 * This function is main part of the program.
 *
 * Parameters:
 * None
 *
 * return value:
 * None
 */

int
main ()
{
    game ();
    
}
