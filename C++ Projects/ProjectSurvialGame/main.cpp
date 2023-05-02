#include <iostream>
#include <sstream>
#include <time.h>
#include <unistd.h>

using namespace std;

class Player {
    public:
    Player(int x, int y){
        health = MAX_HEALTH;
        hunger = MAX_HUNGER;
        thirst = MAX_THIRST;
        coins = MAX_COINS;
        
        this->x = x;
        this->y = y;
        this->score = 0;
        this->coins = 5;
    }
    
    int getScore() const {
        return score;
    }
    
    void takeDamage(int val){
        this->health -= val;
        if(this->health < 0) this->health = 0;
    }
    
    void takeTurn(){
        this->thirst--;
        this->hunger--;
        
        if(this->thirst <= 0){
            this->health--;
            this->thirst = 0;
        }
        
        if(this->hunger <= 0){
            this->health--;
            this->hunger = 0;
        }
        
        this->score++;
    }
    
    string getStats() const {
        stringstream ss;
        sleep(3);
        ss  << "============\n"
            << "Health: " << this->health << "\n" 
            << "Hunger: " << this->hunger << "\n" 
            << "Thirst: " << this->thirst << "\n"
            << "Coins: " << this->coins << "\n"
            << "============\n";
        return ss.str();
    }
    
    bool isAlive() const {
        return this->health > 0;
    }
    
    int Amount() const {
        return this->coins;
    }
    
    void increaseThrist(int val){
        this->thirst = this->thirst + val;
        if(this->thirst > MAX_THIRST) this->thirst = MAX_THIRST;
    }
    
    void increaseHunger(int val){
        this->hunger += val;
        if(this->hunger > MAX_HUNGER) this->hunger = MAX_HUNGER;
    }
    
    void increaseCoins(int val){
        this->coins += val;
        if(this->coins > MAX_COINS) this->coins = MAX_COINS;
    }
    
    void loseCoins(int val){
        this->coins -= val;
        if (this->coins < 0){
            this->coins = 0;
        }
    }
    
    int x, y;
    private:
    int health, hunger, thirst, coins, score;
    const int MAX_HEALTH = 3;
    const int MAX_HUNGER = 5;
    const int MAX_THIRST = 3;
    const int MAX_COINS = 99;
};

class Land {
    public:
    virtual string getDescription() = 0;
    virtual string visit(Player& player) = 0;
};

// TO DO: Define at least 3 more types of derived land types
// TO DO: Add some unique effect to each new type

// 1
class Forest : public Land {
    public:
    string getDescription(){
        return "a densely wooded forest.\n";
    }
    
    string visit(Player& player){
        int randomNum = rand() % 100;
        
        int coinChance = rand() % 100;
        
        sleep(2);
        cout << "." << endl;
        sleep(2);
        cout << "." << endl;
        sleep(2);
        cout << "." << endl;
        
        if(randomNum > 74){
            player.takeDamage(1);
            
            cout <<  "You are attacked by a bear while foraging for berries." << endl;
            
            if (coinChance >= 80){
                player.increaseCoins(3);
                
                cout << "What's this?" << endl;
                sleep(2);
                
                return "There seems to be 3 coins on the ground. Must be your lucky day...well not that lucky. That bear did attack you, but you got money :)";
            }
            
            else{
                return "Ouch!";
            }
        } 
        else {
            player.increaseHunger(1);
            cout << "You forage for berries in the woods and eat a few." << endl;
            
            if (coinChance >= 90){
                player.increaseCoins(1);
                
                cout << "What's this?" << endl;
                sleep(2);
                
                return "There seems to be a coin on the ground. You pick it up";
            }
            
            else{
                return "Tasty!";
            }
        }
    }
};

// 2
class Lake : public Land {
    public:
    string getDescription(){
        return "a clear sparkling lake.\n";
    }
    
    string visit(Player& player){
        
        int coinChance = rand() % 100;
        int lakeDeepness = rand() % 50;
    
        char check;
        
        player.increaseThrist(2);
        
        
        cout << "You visit the lake and drink its clean water" << endl;
        
        sleep(2);
        
        cout << "Oh?" << endl;
        
        sleep(2);
        
        cout << "You see something shiny at the bottom of the lake." << endl;
        
        cout << "The lake is " << lakeDeepness << " feet deep." << endl;
        
        if (lakeDeepness <= 10){
            cout << "Doesn't seem that deep" << endl;
            
            sleep(2);
            
            cout << "Would want to go for it?" << endl;
            cout << "[Y] Yes\nor\n[N] No" << endl;
            cin >> check;
            
            if (check == 'Y'){
                if (coinChance <= 40){
                    player.increaseCoins(1);
                    sleep(2);
                    return "You were able to reach the shiny object! It was a coin! It's a little rusted, but still has monetary value.";
                }
                else{
                    player.takeDamage(1);
                    sleep(2);
                    return "YOWCH! A piranha came out of nowhere and bit you with full force on your hand!";
                }
            }
            else{
                return "You decided to not go for the shiny object, Now it will stay there forever without an owner...Meanie (Not you Dr. Shue)";
            }
        }
        else if (lakeDeepness > 10 && lakeDeepness <= 30){
            cout << "Seems pretty deep, but you feel confident that you can swim down to reach it" << endl;
            
            sleep(2);
            
            cout << "Would want to go for it?" << endl;
            cout << "[Y] Yes\nor\n[N] No" << endl;
            cin >> check;
            
            if (check == 'Y'){
                if (coinChance <= 20){
                    player.increaseCoins(1);
                    sleep(2);
                    return "You were able to reach the shiny object! It was a coin! It's very rusted, but a good ol' cleaning will bring that bad boy back to it's monetary value.";
                }
                else{
                    player.takeDamage(2);
                    sleep(2);
                    return "DADGUMMIT! A snapping turtle stretched it's long neck to bite the hell out of you!";
                }
            }
            else{
                return "You decided to not go for the shiny object, Now it will stay there forever without an owner...Meanie (Not you Dr. Shue)";
            }
        }
            
        else{
            cout << "It seems very deep. You feel no confidence in getting this shiny object" << endl;
            
            sleep(2);
            
            cout << "Would want to go for it?" << endl;
            cout << "[Y] Yes\nor\n[N] No" << endl;
            cin >> check;
            
            if (check == 'Y'){
                if (coinChance <= 10){
                    player.increaseCoins(1);
                    sleep(2);
                    return "You were able to reach the shiny object!...But it was just a ticket that says 'Wonka's Golden Ticket' What good does that do you?";
                }
                else{
                    player.takeDamage(3);
                    sleep(2);
                    return "Dang! It was just a rock. You swim back up and see that there are leeches all over you! OW! Gross! EW!";
                }
            }
            else{
                return "You decided to not go for the shiny object, Now it will stay there forever without an owner...Meanie (Not you Dr. Shue)";
            }
        }
    }
};

// 3
class Bush : public Land {
    public:
    string getDescription(){
        return "a bush vigourously shake\n";
    }
    
    string visit(Player& player){
        int randomNum = rand() % 100;
        
        cout << "You check out the bush and..." << endl;
        
        sleep(2);
        
        if(randomNum > 80){
            player.increaseHunger(2);
            player.increaseCoins(10);
            return "A nice little leprachaun gives you his Lucky Charms along with 10 coins! Money! Money! Money!";
        } 
        else {
            player.takeDamage(2);
            return "A stinky skunk sprays you right in the face!";
        }
    }
};

// 4
class KingCrowd : public Land {
    public:
    string getDescription(){
        return "a bunch of horseriding men with very medieval clothing and one of them is wearing a gold crown\n";
    }
    
    
    string visit(Player& player){
       int randomNum = rand() % 100;
       char choice;
       
        if(randomNum <= 10){ //When the user hears the name
            cout << "...You overhear the name Jerry Lawler..." << endl;
            sleep(2);
            
            cout << "You approach them and they turn around..." << endl;
            cout << "The king asks you to address him and kneel to him" << endl;
            
            sleep(2);
       
            cout << "[A] Kneel and address the name that you overheard" << endl;
            cout << "[B] Kneel and don't address the name" << endl;
            cout << "[C] Don't kneel and address his name" << endl;
            cout << "[D] Do nothing" << endl;
            cout << "What do you do?" << endl;
            
            cin >> choice;
            
            switch(choice){
                case 'A': //Kneel and Address
                    cout << "'Finally, someone who has class' King Lawler says to you" << endl;
                    player.increaseHunger(2);
                    player.increaseThrist(2);
                    player.increaseCoins(20);
                    return "'You look a little skinny, tell you what have some food and water as a reward for your kindness\nYou actually caught me on a good day, Have 20 coins'";
                    break;
                case 'B': // Only Kneel
                    cout << "'Well, tha-" << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "Hey! Address me! You've kneeled, now address me!" << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    player.takeDamage(1);
                    return "'So that's how it's gonna be...You there! Give him a punch he will never forget!";
                    break;
                case 'C': // Only Address
                    cout << "'How dare you! No one says my name without kneeling! Kneel for me! Now!" << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    player.takeDamage(1);
                    return "'So that's how it's gonna be...You there! Give him a kick in the face so hard that he will have to run back to his mommy!";
                    break;
                case 'D': // Nothing
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    player.takeDamage(2);
                    player.loseCoins(10);
                    cout << "'You must be a jester! Do as I sa- You know what? I have no time to wait! Men! Let's run this fopdoodle over!'\nThey run you over with their horses! Ouch!" << endl;
                    sleep(2);
                    cout << "You blackout." << endl;
                    sleep(2);
                    return "Due to the massive amount of pain and when you wake up you find to see that they have taken some of your coins!";
                    break;
                default:
                    break;
            }
            
        }
        else{ //When the user doesn't hear the name
            
            sleep(2);
            cout << "You approach them and they turn around..." << endl;
            sleep(2);
            cout << "A man asks you to address him and kneel to him" << endl;
            sleep(2);
            cout << "His soldiers are blocking your view of the man who spoke" << endl;
            sleep(2);
            cout << "His voice sounds so far away that you can barely hear him so there is no way to know if you recognize the voice" << endl;
       
            sleep(2);
            cout << "What do you do?" << endl;
            
            sleep(1.5);
            cout << "[A] Kneel and guess his name" << endl;
            cout << "[B] Kneel and don't address the name" << endl;
            cout << "[C] Don't kneel and address his name" << endl;
            cout << "[D] Do nothing" << endl;
            cout << "[E] Call him Burger King" << endl;
            cout << "What do you do?" << endl;
            
            cin >> choice;
            
            switch(choice){
                case 'A': //Kneel and Address
                    player.takeDamage(2);
                    sleep(1);
                    return "'That's not even close to my name! Because you have disrespected me, I shall punish you! Men! Let's run him over!'";
                    break;
                case 'B': // Only Kneel
                    cout << "'Well, tha-" << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "Hey! Address me! You've kneeled, now address me!" << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    player.takeDamage(1);
                    return "'So that's how it's gonna be...You there! Give him a punch he will never forget!";
                    break;
                case 'C': // Only Address
                    cout << "'How dare you! No one says my name without kneeling! Kneel for me! Now!" << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    player.takeDamage(1);
                    return "'So that's how it's gonna be...You there! Give him a kick in the face so hard that he will have to run back to his mommy!";
                    break;
                case 'D': // Nothing
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    player.takeDamage(2);
                    player.loseCoins(10);
                    cout << "'You must be a jester! Do as I sa- You know what? I have no time to wait! Men! Let's run this fopdoodle over!'\nThey run you over with their horses! Ouch!" << endl;
                    sleep(2);
                    cout << "You blackout." << endl;
                    sleep(2);
                    return "Due to the massive amount of pain and when you wake up you find to see that they have taken some of your coins!";
                    break;
                case 'E': // Burger King Name
                    player.takeDamage(5);
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    return "'You dare call me that?!?!? You Mandrake mymmerkin! That type of behaviour is forbidden! Off with your head!' Lawler screechs with a disgusted attitude";
                    break;
                default:
                    break;
            }
        }
    }
    };

// 5
class WalkingShop : public Land {
    public:
    string getDescription(){
        return "a skinny man with a big nose carrying a big and heavy looking backpack\n";
    }
    
    string visit(Player& player){
        int randomNum = rand() % 100;
        
        int saleDay = rand() % 100;
        
        char choice;
        
        sleep(2);
        cout << "You walk over towards him and he says...\n'Howdy!'" << endl;
        sleep(2);
        cout << "Before you could even respond, he takes off his backpack and lays out all of his inventory" << endl;
        
        sleep(3);
        
        if (player.Amount() <= 1){
            cout << "'What would yo-" << endl;
            sleep(2);
            cout << "." << endl;
            sleep(2);
            cout << "." << endl;
            sleep(2);
            cout << "." << endl;
            sleep(2);
            cout << "wait a minute...You have money, right?" << endl;
            
            cout << "[Y] Yes\nor\n[N] No" << endl;
            cin >> choice;
            
            if (choice == 'Y'){
                player.takeDamage(2);
                return "'LIAR!' He yells as he gives you the ol' one two";
            }
            else{
                player.increaseHunger(1);
                player.increaseThrist(1);
                sleep(2);
                return "'Oh wow, you have almost no money...well to reward for your honesty. I shall give you some food and water on the house.'";
            }
        }
        else{
            cout << "'My name is Beedle, Your one stop walking shop!'" << endl;
            
            sleep(2);
            
            cout << "'I got all kinds of stuff! Just take a look and see what I got!'" << endl;
            
            sleep(2);
    
            cout << "You have: " << player.Amount() << " Coins" << endl;
            cout << "[A] Piece of Bread: 2 Coins" << endl;
            cout << "[B] Bottle of Water: 3 Coins" << endl;
            cout << "[C] Cake: 10 Coins" << endl;
            cout << "[D] Gatorade: 15 Coins" << endl;
            cout << "[E] Weird Colored Potion: 50 Coins" << endl;
            cout << "[F] Try to rob him" << endl;
            
            cin >> choice;
            
            switch(choice){
                case 'A': // Piece of Bread
                    if (player.Amount() < 2){
                        player.takeDamage(1);
                        sleep(2);
                        return "'Hey! You don't have enough coins! Get outta here!' Beedle screams as he smacks you right across the face";
                    }
                    else{
                        player.loseCoins(2);
                        player.increaseHunger(1);
                        return "'Pleasure doing business with you! ONE PURCHASE AT A TIME!' Beedle yelps as he hurriedly packs up all of his stuff and bolts off";
                    }
                    break;
                case 'B': // Bottle of Water
                    if (player.Amount() < 3){
                        player.takeDamage(1);
                        sleep(2);
                        return "'Hey! Are you trying to rob me?!?! Get outta here!' Beedle screams as he gives you 5 across the face";
                    }
                    else{
                        player.loseCoins(3);
                        player.increaseThrist(1);
                        return "'Pleasure doing business with you! ONE PURCHASE AT A TIME!' Beedle yelps as he hurriedly packs up all of his stuff and bolts off";
                    }
                    break;
                case 'C': // Cake
                    if (player.Amount() < 10){
                        player.takeDamage(2);
                        sleep(2);
                        return "'Hey! What are trying to do, poor man! Get outta here!' Beedle screams as he gives you a powerful punch across your face";
                    }
                    else{
                        player.loseCoins(10);
                        player.increaseHunger(3);
                        return "'Pleasure doing business with you! ONE PURCHASE AT A TIME!' Beedle yelps as he hurriedly packs up all of his stuff and bolts off";
                    }
                    break;
                case 'D': // Gatorade
                    if (player.Amount() < 15){
                        player.takeDamage(2);
                        sleep(2);
                        return "'...Dude...come on...you ain't got the mula to buy this...Get outta here!' Beedle whispers as he gives you kicks you right on your face";
                    }
                    else{
                        player.loseCoins(15);
                        player.increaseThrist(3);
                        return "'Pleasure doing business with you! ONE PURCHASE AT A TIME!' Beedle yelps as he hurriedly packs up all of his stuff and bolts off";
                    }
                    break;
                case 'E': // Weird Colored Potion
                    if (player.Amount() < 50){
                        player.takeDamage(2);
                        player.loseCoins(99);
                        cout << "'HOLD IT! That is my most expensive item! You do NOT have the coins to get that so Get outta here!' Beedle screams as he picks you up and slams you on the ground! That's gotta leave a mark!" << endl;
                        return "You black out and when you wake up you realize he has stolen all your coins!";
                    }
                    else{
                        player.loseCoins(50);
                        player.increaseThrist(5);
                        player.increaseHunger(3);
                        cout << "You drink the potion and immediately feel a surge through your body. You fall to the ground and pain flows through your body and then all of the sudden the pain stops.\nYou feel like a new man now!" << endl;
                        return "'Pleasure doing business with you! ONE PURCHASE AT A TIME!' Beedle yelps as he hurriedly packs up all of his stuff and bolts off";
                    }
                    break;
                case 'F': // Rob Him
                    player.takeDamage(3);
                    return "As you try to snatch one of the items, he immediately grabs your arm and barks 'No one steals from me!' as gives you a right hook that feels like Mike Tyson just punched you.";
                    break;
                default:
                    break;
            }
            
            
        }
    }
};

// 6
class FiddleMan : public Land {
    public:
    string getDescription(){
        return "a man with a straw hat playing a golden fiddle\n";
    }
    
    int yawnChance = rand() % 100;
    
    string visit(Player& player){
        
        char choice;
        char yawnchoice;
        
        sleep(2);
        cout << "As you draw near him, he jumps up and says 'How ya doin pardner? Ma name's Johnny' with an accent that sounded as if he was from Georgia" << endl;
        
        sleep(3);
        cout << "Would you like to hear something I have been working on?" << endl;
        
        sleep(1);
        cout << "[Y] Yes\nor\n[N] No" << endl;
        cin >> choice;
        
        if (choice == 'Y'){
            sleep(2);
            cout << "'Boy, you have made me happier than a pig rollin 'round in mud'" << endl;
            sleep(2);
            cout << "Johnny then plays the fiddle so well that you couldn't think the devil could do any better" << endl;
            
            sleep(2);
            cout << "He plays, but then..." << endl;
            sleep(3);
            cout << "Uh oh..." << endl;
            sleep(2);
            cout << "You feel a yawn coming on. Now that you think about it, you didn't really get much sleep last night." << endl;
            sleep(3);
            cout << "What do you do?" << endl;
            sleep(1);
            cout << "[A] Yawn without a care in the world" << endl;
            cout << "[B] Explain why you yawn " << endl;
            cout << "[C] Hold in the yawn with all your might" << endl; // He finishes the song and thanks you by giving you coins
            cout << "[D] Yawn, but cover it up by sounding like you are singing like you're in an Opera" << endl; // He stops playing and says that was kinda weird, please get away from me
        
            cin >> choice;
            
            switch(choice){
                case 'A': // Yawm with no care
                    player.takeDamage(1);
                    cout << "You yawn" << endl;
                    sleep(2);
                    return "'Ok, I know the fiddle isn't the most interesting instrument, but did you really have to yawn? That really hurt me deep'\nJohnny pauses then out of nowhere he gives you a strike on the head";
                    break;
                case 'B': // Yawn with explanation
                    player.takeDamage(1);
                    cout << "You yawn, but before he reprimands you, you explain why you yawned" << endl;
                    sleep(2);
                    cout << "'Oh, you're tired' He says using air quotes.\n'A likely story, why can't you just be honest with me?'" << endl;
                    return "Before you could respond, he clocks you over the head and shoves you away";
                    break;
                case 'C': // Trying not to yawn
                
                    cout << "You try your hardest not to yawn..." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    sleep(2);
                    cout << "." << endl;
                    if (yawnChance <= 70){
                        player.takeDamage(1);
                        return "You fail to not yawn! He sees that you yawn. He stops playing and without saying anything slaps you across the face and walks away.";
                    }
                    else{
                        player.increaseHunger(1);
                        player.increaseThrist(1);
                        cout << "You successfully stop from yawning!" << endl;
                        sleep(2);
                        cout << "Wow, when I play my fiddle, people usually yawn. To reward you, here you go" << endl;
                        return "He gives you a Bo-Berry biscuit and a cup of sweet-tea.\nRefreshing!";
                    }
                    break;
                case 'D': // Yawn Opera Singing
                    player.increaseCoins(2);
                    sleep(2);
                    cout << "Wow, that was a weird addition to my fiddle playing...ummm...i'm gonna pay you to never do that again" << endl;
                    return "He gives you two coins! Cha-ching!";
                    break;
                default:
                    break;
            }
            
        }
        
        else{
            sleep(2);
            cout << "." << endl;
            sleep(2);
            cout << "." << endl;
            sleep(2);
            cout << "." << endl;
            cout << "Wow, that was mean. I'm gonna just walk away now to not make this awkard" << endl;
            return "He walks away dejectedly as you hear him start to cry a little bit\nGood job! You made a grown man cry!";
        }
        
        }
        
};

// 7
class TreasureChest : public Land {
    public:
    string getDescription(){
        return "what looks to be...a treasure chest?\n";
    }
    
    int treasureChance = rand() % 101;
    string visit(Player& player){
        
        char choice;
        
        sleep(2);
        cout << "Looks a little rusted...there's no lock either..." << endl;
        
        sleep(3);
        cout << "Would you want to open it?" << endl;
        
        sleep(1);
        cout << "[Y] Yes\nor\n[N] No" << endl;
        cin >> choice;
        
        sleep(2);
        if (choice == 'Y'){
            cout << "You open the chest and it's..." << endl;
            sleep(2);
            
            if (treasureChance >= 100){
                player.increaseCoins(99);
                sleep(2);
                return "HOLY GUACAMOLE, THERE IS SO MANY COINS IN THE CHEST\nYou fill your wallet with as many coins as you can";
            }
            else if (treasureChance >= 88 && treasureChance < 100){
                player.increaseHunger(5);
                cout << "Wow! It's not coins, but even better!\nIt's an MRE(Meal Ready to Eat), its the best rated one too! The Chilli Mac & Cheese package!" << endl;
                sleep(3);
                return "The scrumptious food filled you right up!";
            }
            else if (treasureChance >= 75 && treasureChance < 88){
                player.increaseThrist(3);
                cout << "Wow! It's not coins, but it's pretty good!\nIt's a gallon full of water!" << endl;
                sleep(2);
                return "The gallon is refreshing!";
            }
            else if (treasureChance >= 50 && treasureChance < 75){
                player.increaseCoins(30);
                return "Great! You found 30 coins in it! Could be handy later in your adventure...";
            }
            else if (treasureChance >= 25 && treasureChance < 50){
                player.increaseThrist(1);
                cout << "Hmm. It's a half-full bottle of water. You're thirsty, so you drink it anyways!" << endl;
                sleep(3);
                return "The water bottle is somewhat refreshing.";
            }
            else {
                player.increaseHunger(1);
                cout << "A lunchables box? Hey, at least it's the pizza one." << endl;
                sleep(3);
                return "It's a lunchables, you know, made for children, so it doesn't fill you up as much as you wanted it to.";
            }
        }
            
        else{
            return "Really? It's a treasure chest.\nFine, it's your choice...a weird one, but that's on you.";
            }
        
        
    }
    
};

// 8
//class LemonadeStand : public Land {};
    //A  little stand that says "Lemonade!"\nYou see a little girl with a woman that looks like she is in her late 20s maybe her aunt in the stand
    // random price of coins from 1-10 coins
        //No money? She starts screaming with a screech that breaks the sound barrier
        //What would you like to do?
            //A: Buy it like normal
                //'Thank you, please come again sometime' she says as she waves you goodbye
            //B: Bargain
                //'Dude, are you seriously gonna bargain with a little girl?' The aunt says disappointedly
            //C: Steal the lemonade
                //She calls for someone named Megan, you look behind you and when you look forward again
                //a lifelike robot doll and she says "give the lemonade back" with her robot eyebrows furrowing
                    //A: You are scared and give the lemonade back
                    //B: Run away again
                        //The robot doll runs towards you on all fours and you run through a densley forest and you feel that you are safe
                        //You look around and nothing seems to be there, but then you see the robot lunge towards you and you have a quick choice to make
                        //A: Throw the lemonade at the robot
                            //The lemonade seems to get into her circuits and she malfunctions and you finally are able to successfully flee
                        //B: Dodge out of the way
                            //You will always fail to dodge




const int MAP_SIZE = 10;
Land* map[MAP_SIZE][MAP_SIZE];

void populateMap(){
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            // TO DO: Modify this code to add your new land types
            int randomNum = rand() % 7;
            switch(randomNum){
                case 0: // Forest
                    map[i][j] = new Forest;
                    break;
                case 1: // Lake
                    map[i][j] = new Lake;
                    break;
                case 2: // Bush
                    map[i][j] = new Bush;
                    break;
                case 3: // King Interaction
                    map[i][j] = new KingCrowd;
                    break;
                case 4: // Traveling Merchant
                    map[i][j] = new WalkingShop;
                    break;
                case 5: // Traveling Merchant
                    map[i][j] = new FiddleMan;
                    break;
                case 6: // Traveling Merchant
                    map[i][j] = new TreasureChest;
                    break;    
                default:
                    cout << "Invalid land type selected" << endl;
                    break;
            }
        }
    }
}

int main(){
    srand(time(0));
    
    populateMap();
    
    Player player(MAP_SIZE/2, MAP_SIZE/2);
    
    cout << "You wake up and find yourself lost in the middle of a strange wilderness.\n" << endl;
    
    // TODO: Handle boundary conditions (e.g., if index out of bounds north, you index the south-most location)
    
    while(player.isAlive()){
        sleep(3);
        if (player.y == 0){
            cout << "To the north: You see " << map[player.x][10]->getDescription() << endl;
            cout << "To the east: You see " << map[player.x + 1][player.y]->getDescription() << endl;
            cout << "To the south: You see " << map[player.x][player.y + 1]->getDescription() << endl;
            cout << "To the west: You see " << map[player.x - 1][player.y]->getDescription() << endl;
        }
        else if (player.x == 10){
            cout << "To the north: You see " << map[player.x][player.y - 1]->getDescription() << endl;
            cout << "To the east: You see " << map[0][player.y]->getDescription() << endl;
            cout << "To the south: You see " << map[player.x][player.y + 1]->getDescription() << endl;
            cout << "To the west: You see " << map[player.x - 1][player.y]->getDescription() << endl;
        }
        else if (player.y == 10){
            cout << "To the north: You see " << map[player.x][player.y - 1]->getDescription() << endl;
            cout << "To the east: You see " << map[player.x + 1][player.y]->getDescription() << endl;
            cout << "To the south: You see " << map[player.x][0]->getDescription() << endl;
            cout << "To the west: You see " << map[player.x - 1][player.y]->getDescription() << endl;
        }
        else if (player.x == 0){
            cout << "To the north: You see " << map[player.x][player.y - 1]->getDescription() << endl;
            cout << "To the east: You see " << map[player.x + 1][player.y]->getDescription() << endl;
            cout << "To the south: You see " << map[player.x][player.y + 1]->getDescription() << endl;
            cout << "To the west: You see " << map[10][player.y]->getDescription() << endl;
        }
        else{
            cout << "To the north: You see " << map[player.x][player.y - 1]->getDescription() << endl;
            cout << "To the east: You see " << map[player.x + 1][player.y]->getDescription() << endl;
            cout << "To the south: You see " << map[player.x][player.y + 1]->getDescription() << endl;
            cout << "To the west: You see " << map[player.x - 1][player.y]->getDescription() << endl;
        }
        
        cout << "Which way will you go? Enter N, E, S, or W:" << endl;
        char userInput;
        cin >> userInput;
        
        switch(userInput){
            case 'N':
                if (player.y == 0){
                    player.y = player.y + 10;
                }
                else{
                    player.y = player.y - 1;
                }
                break;
            case 'E':
                if (player.x == 10){
                    player.x = player.x - 10;
                }
                else{
                    player.x = player.x + 1;
                }
                break;
            case 'S':
                if (player.y == 10){
                    player.y = player.y - 10;
                }
                else{
                    player.y = player.y + 1;
                }
                break;
            case 'W':
                if (player.x == 0){
                    player.x = player.x + 10;
                }
                else{
                    player.x = player.x - 1;
                }
                break;
            default:
                break;
        }
        
        cout << map[player.x][player.y]->visit(player) << endl;
        
        cout << player.getStats() << endl;
        player.takeTurn();
    }
    
    if (player.Amount() <= 10){
        cout << "You died a poor man." << endl;
    }
    else if(player.Amount() <= 30 && player.Amount() > 10){
        cout << "You died with a decent amount of money." << endl;
    }
    else if(player.Amount() <= 50 && player.Amount() > 30){
        cout << "You died with a good amount money! Good job!" << endl;
    }
    else if(player.Amount() <= 70 && player.Amount() > 50){
        cout << "Congrats! You died a rich man" << endl;
    }
    else if(player.Amount() <= 98 && player.Amount() > 70){
        cout << "Wow! You died a very rich man!" << endl;
    }
    else{
        cout << "Wait, ummm...how did you reach the max? That's a very small chance. Woohoo? I guess?...I'm gonna be honest. I think you cheated" << endl;
    }
    cout << "Your score: " << player.getScore() << endl;
    
    return 0;
}