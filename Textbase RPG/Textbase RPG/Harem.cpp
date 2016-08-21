#include "Harem.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Harem::Harem()
{
	girlHistory = 0;
}


Harem::~Harem()
{
}


void Harem::showGirls()
{
	ifstream Girl("Girl.txt");
	getline(Girl, temp);
	while (!Girl.eof()) {
		getline(Girl, name, '|');
	}
}

void Harem::showGirlTraits() 
{
	ifstream GirlTraits("GirlTraits.txt");
	getline(GirlTraits, temp);
	while (!GirlTraits.eof()){
		GirlTraits >> girlNumber;
		getline(GirlTraits, name, '|');
		GirlTraits>> age >> birthday >> education >> occupation >> cupSize >> hobby >> favoriteColor >> mostDesiredtrait >> lovesGifttype >> likeFoodType;
	}
}

int Harem::chooseGirl(int input)
{
	cin >> input;
	switch (input) {
	case 1: {

		cout << "You have choosen to go for Tiffany Maye" << endl;
		cin >> input;
		switch (input) {
			cout << "1. Talk to her." << endl;
			cout << "2. Ask her on a date." << endl;

		case 1:
			talk(2);
			break;
		case 2:
			dateGirl();
			break;
		}

		break;
	}
	case 2: {

		cout << "You have choosen to go for Aiko Yumi" << endl;
		switch (input) {
			cout << "1. Talk to her." << endl;
			cout << "2. Ask her on a date." << endl;
		case 1:
			talk(input);
			break;
		case 2:
			dateGirl();

			break;
		}
		break;
	}
	case 3: {
		cout << "You have choosen to go for Audrey Belrose" << endl;
		switch (input) {
			cout << "1. Talk to her." << endl;
			cout << "2. Ask her on a date." << endl;
		case 1:
			talk(input);
			break;
		case 2:
			dateGirl();
			break;
		}
		break;
	}
	case 4:
	{
		cout << "You have choosen to go for Jessi Maye" << endl;
		switch (input) {
			cout << "1. Talk to her." << endl;
			cout << "2. Ask her on a date." << endl;
		case 1:
			talk(input);
			break;
		case 2:
			dateGirl();
			break;
		}

		break;

	}
	default:
		cout << "Error, type what you see bruh, quitting.\n";
		break;

	}

	return 0;
}

void Harem::talk(int input)
{

	switch (input) {
	case 1:
		
		girlHistory = 1;
		//After player already talked to this girl before, this dialogue will apprea instead
		if (girlHistory == 1) {
			dialogue = rand() % 2 + 1;
			if (dialogue == 1) {
				cout << "Ahh it feels good to be finally done with class." << endl;
			}
			else if (dialogue == 2) {
				cout << "Hi. Funny running into you here." << endl;
			}
			else if (dialogue == 2) {
				cout << "Oh, Hi! How's it going?" << endl;
			}
			else if (girlHistory == 0) {

				cout << "You chose to talk to Tiffany Maye." << endl;
				cout << "Hey, dont take this the wrong way, but i just thought you were cute and had to say hi." << endl;
				cout << "Girl : Who? Me? Ohh, no! I'm not so cute... but thanks for the compliment!" << endl;
				cout << "Girl : I haven't seen you around here before. Are you a regular?" << endl;
				cout << "Yeah i work here. Barista Handsome they call me." << endl;
				cout << "Girl : Come on,give me a break. Stop teasing me!" << endl;
				cout << "Girl : My name is Tiffany by the way. Its nice to meet you. " << endl;
				cout << "You seem like a cool guy, i hope to see you around here!" << endl;
			}
		}
			//Tiffany's way to ask the player what they wanna know about her
			if (dialogue == 1) {

				cout << "So, what do you wanna know about me?" << endl;
			}
			else if (dialogue == 2) {

				cout << "What's shakin bacon?" << endl;
			}
			else if (dialogue == 3) {

				cout << "Something on you mind?" << endl;
			}

			//Then the player wanna ask wat question comes in
			switch (input) {
			case 1:
				cout << "Hey, if you dont mind me asking, what cup size are you rocking?" << endl;
				cout << "Really? If you must know, I'm a C-cup!" << endl;
			case 2:
				cout << "Lame question, but whats your Favorite Color?" << endl;
				cout << "Pink, but not exactly pink, i guess Milky Pink?" << endl;
			case 3:
				cout << "What do you do? Like, for work, i mean." << endl;
				cout << "I'm still in school you dumbo!" << endl;
			case 4:
				cout << "What would you say your main hobby is?" << endl;
				cout << "I really enjoy cheerleading, ive never missed a practice!" << endl;
			case 5:
				cout << "So i won't forget it, when is your birthday?" << endl;
				cout << "Oh!, its right before the holdays, December 22nd!" << endl;
			}



			break;
			if (dialogue == 1) {
				cout << "Shit is it that time already? Opps." << endl;
			}
			else if (dialogue == 2) {
				cout << "Ill see you later!" << endl;
			}
			else if (dialogue == 3) {
				cout << "Pssh, i see how it is" << endl;
			}
			else if (dialogue == 4) {
				cout << "Enjoy your night!" << endl;
			}
			else if (dialogue == 5) {
				cout << "Buh-Bye!" << endl;
			}



	case 2:

		girlHistory = 1;
		//After player already talked to this girl before, this dialogue will apprea instead
		if (girlHistory == 1) {
			dialogue = rand() % 2 + 1;
			if (dialogue == 1) {
				cout << "Hey hot stuff." << endl;
			}
			else if (dialogue == 2) {
				cout << "Oh! Shiiit.. dont sneak up on me like that!" << endl;
			}
			else if (dialogue == 3) {
				cout << "Great, you can entertain me. Sooooo bored." << endl;
			}
			else if (dialogue == 4) {
				cout << "You're still powling around?" << endl;
			}
			else if (girlHistory == 0) {
				cout << "You chose to talk to Aiko Yumi." << endl;
				cout << "Hey can you teach me karate?" << endl;
				cout << "Girl : Oh my god! Could you please be more racist?" << endl;
				cout << "Haha, but, for real, what's up? You look a little bummed out over here." << endl;
				cout << "Girl : Oh no, im just trying to relax and get away from life. I'm a teacher you know?" << endl;
				cout << "Oh, so you've got that sexy teacher angle going then?" << endl;
				cout << " I dont know about that, but i have a couple of students that will agree with you, thanks for coming tho, i needed a good laugh, my student call me Ms Yumi, but you can call me Aiko." << endl;
			}
		}

			//Aiko's way to ask the player what they wanna know about her
			if (dialogue == 1) {
				cout << "Yeeeeess?" << endl;
			}
			else if (dialogue == 2) {
				cout << "Mmmmhmm?" << endl;
			}
			else if (dialogue == 3) {
				cout << "Something i can help you with?" << endl;
			}
			//Then the player wanna ask wat question comes in
			switch (input) {
			case 1:
				cout << "I've got to know, what cup size are you rocking?" << endl;
				cout << "Aiko : Woow, how romantic... I'm rocking D's." << endl;
			case 2:
				cout << "Lame question, but whats your Favorite Color?" << endl;
				cout << "Thats when i know you have nothing to talk about haha, i like green." << endl;
			case 3:
				cout << "What did you study in collge?" << endl;
				cout << "I've got a master degree in Mathematics, and i regret it everyday." << endl;
			case 4:
				cout << "Whats your hobby?" << endl;
				cout << "Sleeping... No wait! Gambling!" << endl;
			case 5:
				cout << "So i won't forget it, when is your birthday?" << endl;
				cout << "I'm sure you'll forget anyway, its November 9th." << endl;
			}
			break;

			if (dialogue == 1) {
				cout << "Hopefully, i'll see you later?" << endl;
			}
			else if (dialogue == 2) {
				cout << "Be a good boy out there." << endl;
			}
			else if (dialogue == 3) {
				cout << "Awwww, really?" << endl;
			}
			else if (dialogue == 4) {
				cout << "Try to keep those dreams about me under control, alright?" << endl;
			}


	case 3:

		girlHistory = 1;
		//After player already talked to this girl before, this dialogue will apprea instead
		if (girlHistory == 1) {
			dialogue = rand() % 2 + 1;
			if (dialogue == 1) {
				cout << "Umm, is there something I can help you with?" << endl;
			}
			else if (dialogue == 2) {
				cout << "Oh... Hey." << endl;
			}
			else if (dialogue == 3) {
				cout << "I had a feeling you were gonna show up." << endl;
			}
			else if (dialogue == 4) {
				cout << "Oh god, this guy?" << endl;
			}
			else if (girlHistory == 0) {
				cout << "You chose to talk to Audrey Belrose." << endl;
				cout << "Girl :Uhh, could you move please? You're kind of in my way." << endl;
				cout << "In a minute, I'm not finished checking you out." << endl;
				cout << "Girl :Uhh, eewww? what are you doing here anyways? Besides creeping on girls." << endl;
				cout << "Just the creeping thing pretty much." << endl;
				cout << "At least, you're honest, well, youre gonna have to do better than that. Sorry! But you did put an effor i guess, and youre kinda cute. Ill tell you what, if you're lucky, maybe we can go get high sometimes, you down?" << endl;
				cout << "Erryday." << endl;
				cout << "Niiice. Names Audrey, get at me if you wanna make thing crazy... Now, if you dont mind, can you get the ♥♥♥♥ outta my way?" << endl;
			}
		}
			//Audrey's way to ask the player what they wanna know about her
			if (dialogue == 1) {
				cout << "Yeah? Out with it." << endl;
			}
			else if (dialogue == 2) {
				cout << "What?" << endl;
			}
			//Then the player wanna ask wat question comes in
			switch (input) {
			case 1:
				cout << "Hey, if you dont mind me asking, what cup size are you rocking?" << endl;
				cout << "B, take it or leave it, boobs arent everything you know?" << endl;
			case 2:
				cout << "Lame question, but whats your Favorite Color?" << endl;
				cout << "Its red. If you cant remember that, i'm gonna kill you." << endl;
			case 3:
				cout << "What are you doing for a living right now?" << endl;
				cout << "Work? Bitch I'm going to school, what the ♥♥♥♥ do you expect?" << endl;
			case 4:
				cout << "What would you say your hobby is?" << endl;
				cout << "I like to go shopping, especially if its someone else's money." << endl;
			case 5:
				cout << "So i won't forget it, when is your birthday?" << endl;
				cout << "April 6th, actually, please forget about it." << endl;

			}
			break;
			if (dialogue == 1) {
				cout << "Uhh yeah, okay.. Byeee..." << endl;
			}
			else if (dialogue == 1) {
				cout << "Byeee!" << endl;
			}
	case 4:

		girlHistory = 1;
		//After player already talked to this girl before, this dialogue will apprea instead
		if (girlHistory == 1) {
			dialogue = rand() % 2 + 1;
			if (dialogue == 1) {
				cout << "Hey hot stuff." << endl;
			}
			else if (dialogue == 2) {
				cout << "How's my number one guy doing?" << endl;
			}
			else if (dialogue == 3) {
				cout << "Hiii daddy...." << endl;
			}
			else if (dialogue == 4) {
				cout << "Oh goodie! My sexy boyfriend is here." << endl;
			}
			else if (girlHistory == 0) {
				cout << "You chose to talk to Jessi Maye." << endl;
				cout << "How much?" << endl;
				cout << "Woman : How much do'y got? I dont think i had the pleasure of meeting you, the cute ones are always hiding. Hun, do me a favor and help me out with my empty glass? Pretty Please?" << endl;
				cout << "What's in it for me?" << endl;
				cout << "Woman : Oohh, i can make it worth your while sweetie. Trust Me." << endl;
				cout << "What sould we do about the fact that we're desperately attracted to each other?" << endl;
				cout << "Awww, you're desperately attracted to me? You're sweet,Only one way to find out, huh? You havent even asked my name yet, I'm more than just a pretty face you know, most gentlemen of your age know me as Misty, but you can call me Jessie." << endl;
			}
		}

			//Jessi's way to ask the player what they wanna know about her
			if (dialogue == 1) {
				cout << "You can ask me anything you like..." << endl;
			}
			else if (dialogue == 2) {
				cout << "Is there anything else you'd like to know about me?" << endl;
			}
			else if (dialogue == 3) {
				cout << "Something you need from me, sweetie?" << endl;
			}
			//Then the player wanna ask wat question comes in
			switch (input) {
			case 1:
				cout << "I've got to know, what cup size are you rocking?" << endl;
				cout << "These puppies? Double D's , 100% natural too." << endl;
			case 2:
				cout << "Lame question, but whats your Favorite Color?" << endl;
				cout << "I think orange is pretty cute, so ill go with that." << endl;
			case 3:
				cout << "What are you doing for a living right now?" << endl;
				cout << "I'm an actress... you seee, i make very special movies for my fans." << endl;
			case 4:
				cout << "What would you say your main hobby is?" << endl;
				cout << "My main hobby.. Hmm, does getting drunk count?" << endl;
			case 5:
				cout << "So i won't forget it, when is your birthday?" << endl;
				cout << "I was born on the 27th of January." << endl;

			}
			break;
			if (dialogue == 1) {
				cout << "Until next time." << endl;
			}
			else if (dialogue == 2) {
				cout << "But.. whos gonna keep me warm tonight?" << endl;
			}
			else if (dialogue == 3) {
				cout << "You keep yourself away from those younger girl okay?" << endl;
			}
			else if (dialogue == 4) {
				cout << "Sweet dreams..." << endl;
			}
			else if (dialogue == 5) {
				cout << "Kisses!" << endl;
			}

	default:
		cout << "HUEUEUEUE" << endl;

		}
	}

void Harem::findGirl()
{
	cout << "Find another girl.";
	chooseGirl(2);
	system("pause");
}

void Harem::dateGirl()
{
	int input;
	cin >> input;
	//this switch needs to be random(as in the switch case randoms which question to be asked
	switch (input) {
	//Tiffany's Questions
	case 1:
		cout << "Hey! Question time!" << endl;
		//Function to add here : Random question to be asked
		switch (input) {
			input = rand() % 2 + 1;
		case 1:
			cout << "Do you believe in extraterrestrial stuff? You know, like aliens and that?" << endl;

			switch (input) {
			case 1:
				cout << "They're real, believe me. I was visited once when I was a kid." << endl;
				break;
			case 2:
				cout << "I'll believe it when I see it." << endl;
				break;
			case 3:
				cout << "You never know whats our there. Its a pretty big universe." << endl;
				break;

			}
			if (playerSelection = 2) {
				cout << "Okay good, my friend Nikki is like obessed with them, shes nuts!" << endl;

				//Here asnwer correct = (+affection)
				if (playerSelection == 1 || playerSelection == 3)
					cout << "Oh, okay.";
			}
		case 2:
			cout << "Do you still talk with any of your ex's?" << endl;

			switch (input) {
			case 1:
				cout << "God no. Those sluts can get bent." << endl;
				break;
			case 2:
				cout << "Yeah I keep in touch with some of them." << endl;
				break;
			case 3:
				cout << "Well that would require having a girlfriend." << endl;
				break;

			}
			if (playerSelection == 2) {
				cout << "Thats really cool, its nice when you can still be friends." << endl;
				//Here asnwer correct = (+affection)
				if (playerSelection == 1 || playerSelection == 3)
					cout << "Oh, okay.";

			}
		case 3:
			cout << "Have you ever cheated on anybody? Be honest." << endl;

			switch (input) {
			case 1:
				cout << "I lost count around forty." << endl;
				break;
			case 2:
				cout << "Nope. Not yet anyway." << endl;
				break;
			case 3:
				cout << "Yeah, but only like seven other chicks." << endl;
				break;

			}
			if (playerSelection == 2) {
				cout << "Wow! I thought you would be the type of boy that plays with peoples feeling, i guess im wrong, teehee." << endl;
				//Here asnwer correct = (+affection)
				if (playerSelection == 1 || playerSelection == 3)
					cout << "Oh, okay.";
				
			}
			break;
		case 4:
			cout << "Hey, question. Do you remember what color i like?" << endl;

			switch (input) {
			case 1:
				cout << "Green." << endl;
				break;
			case 2:
				cout << "Milky Pink" << endl;
				break;
			case 3:
				cout << "Sky blue" << endl;
				break;
			}
			if (playerSelection == 2) {
				cout << "Wow! I cant believe you remember, most guys would have forgotten by now." << endl;
				//Here asnwer correct = (+affection)
				if (playerSelection == 1 || playerSelection == 3)
					cout << "You jerk! Wrong!";
			}
		}
		

	//Aiko's questions
	case 2:
		cout << "I've been wondering." << endl;
		//Function to add here : Random question to be asked
		switch (input) {
			input = rand() % 2 + 1;
		case 1:
			cout << "How do you define happiness?" << endl;

			switch (input) {
			case 1:
				cout << "Hapiness is when you settle down and have a happy family." << endl;
				break;
			case 2:
				cout << "I don't know... I guess I'm still searching for that answer." << endl;
				break;
			case 3:
				cout << "I dont care about hapiness at all!" << endl;
				break;

			}
			if (playerSelection = 2) {
				cout << "Yep, same here. Please, let me know when you find it." << endl;
				//Here asnwer correct = (+affection)
				if (playerSelection == 1 || playerSelection == 3)
					cout << "Oh, okay.";
			}
			break;
		case 2:
			cout << "What's your ideal, perfect vacation like?" << endl;

			switch (input) {
			case 1:
				cout << "A tropical island or beah resort." << endl;
				break;
			case 2:
				cout << "This is lame but I prefer to just stay home and relax." << endl;
				break;
			case 3:
				cout << "A cozy winter cottage or ski resort." << endl;
				break;

			}
			if (playerSelection == 2) {
				cout << "No I'm with you, who needs to stress a traveling?" << endl;
				//Here asnwer correct = (+affection)
				if (playerSelection == 1 || playerSelection == 3)
					cout << "Oh, okay.";

			}
			break;
		case 3:
			cout << "What is your favorite part of the female body?" << endl;

			switch (input) {
			case 1:
				cout << "The sexy brain." << endl;
				break;
			case 2:
				cout << "The chest... Region." << endl;
				break;
			case 3:
				cout << "I'm a leg man myself." << endl;
				break;

			}
			if (playerSelection == 2) {
				cout << "Of course! Now i see why you came up to me." << endl;
				//Here asnwer correct = (+affection)
				if (playerSelection == 1 || playerSelection == 3)
					cout << "Oh, okay.";

			}
			break;
		}

	case 3:
		cout << "Question for ya." << endl;
		//Function to add here : Random question to be asked
		switch (input) {
			input = rand() % 2 + 1;
		case 1:
			cout << "If someone said they saw me with another guy, what would your reaction be?" << endl;

			switch (input) {
			case 1:
				cout << "Ill ask you if its real or not." << endl;
				break;
			case 2:
				cout << "I'd break his ♥♥♥♥ing face." << endl;
				break;
			case 3:
				cout << "I dont care." << endl;
				break;

			}
			if (playerSelection = 2) {
				cout << "Nice! You better beat him up real good." << endl;
				//Here asnwer correct = (+affection)
				if (playerSelection == 1 || playerSelection == 3)
					cout << "Oh, okay.";
			}
			break;
		case 2:
			cout << "Do you still talk to any of the girls you used to ♥♥♥♥?" << endl;

			switch (input) {
			case 1:
				cout << "Yeah, around forty i guess." << endl;
				break;
			case 2:
				cout << "Hell no!" << endl;
				break;
			case 3:
				cout << "Idk, like maybe?" << endl;
				break;

			}
			if (playerSelection == 2) {
				cout << "Yeah you better not be talking to any of those ♥♥♥♥es beacuse id slap the ♥♥♥♥ outta them." << endl;
				//Here asnwer correct = (+affection)
				if (playerSelection == 1 || playerSelection == 3)
					cout << "Oh, okay.";

			}
			break;
		case 3:
			cout << "What kind of people do you just ♥♥♥♥ing hate to even look at??" << endl;

			switch (input) {
			case 1:
				cout << "People who look good." << endl;
				break;
			case 2:
				cout << "I can't stand fake ♥♥♥ hoes.." << endl;
				break;
			case 3:
				cout << "I dont hate anyone." << endl;
				break;

			}
		case 4:
			cout << "So, what my favorite color?" << endl;
			switch (input) {
			case 1:
				cout << "Green." << endl;
				break;
			case 2:
				cout << "Velvet red." << endl;
				break;
			case 3:
				cout << "Sky blue" << endl;
				break;
			}

			if (playerSelection == 2) {
				cout << "Thats right! Those ♥♥♥ hoes deserve to get ♥♥♥ed." << endl;
				//Here asnwer correct = (+affection)
				if (playerSelection == 1 || playerSelection == 3) {
					cout << "Oh, okay.";
				}
				if (playerSelection == 4) {
					cout << "What'd you do, write it down?" << endl;
				}
			}
			break;
		
		}


	case 4:
		cout << "Something you need from me, sweetie?" << endl;
		//Function to add here : Random question to be asked
		switch (input) {
			input = rand() % 2 + 1;
		case 1:
			cout << "Have you ever slept around while dating someone?" << endl;

			switch (input) {
			case 1:
				cout << "Not a change. I wouldn't dream of it." << endl;
				break;
			case 2:
				cout << "Yeah, I'm not exactly the best at commitment." << endl;
				break;
			case 3:
				cout << "Just one and it was the biggest mistake of my life." << endl;
				break;

			}
			if (playerSelection = 2) {
				cout << "Thats okay honey, its not exactly my cup of tea either." << endl;
				//Here asnwer correct = (+affection)
				if (playerSelection == 1 || playerSelection == 3)
					cout << "Oh, okay.";
			}
			break;
		case 2:
			cout << "How important is family to you?" << endl;

			switch (input) {
			case 1:
				cout << "I never liked my family." << endl;
				break;
			case 2:
				cout << "It's the most important thing in the world." << endl;
				break;
			case 3:
				cout << "Not at all." << endl;
				break;

			}
			if (playerSelection == 2) {
				cout << "Same as me, too bad my relatioship with my daughther is not the best." << endl;
				//Here asnwer correct = (+affection)
				if (playerSelection == 1 || playerSelection == 3)
					cout << "Oh, okay.";

			}
			break;
		case 3:
			cout << "How would you feel about your partner seeing other people on the side ? " << endl;

			switch (input) {
			case 1:
				cout << "I think I'd be pretty upset about it." << endl;
				break;
			case 2:
				cout << "She can do whatever she wants. I don't own her." << endl;
				break;
			case 3:
				cout << "It depends how serious the relationship is." << endl;
				break;

			}
			if (playerSelection == 2) {
				cout << "Yeah, its not a big deal." << endl;
				//Here asnwer correct = (+affection)
				if (playerSelection == 1 || playerSelection == 3)
					cout << "Oh, okay.";

			}
		}
		break;
	}
}

int Harem::menu()
{
	int input;

	cout << "1. Find girl to talk to.\n";
	cout << "2. Talk to Girl.\n";
	cout << "3. Girl Finder.\n";
	cout << "4. Date Girl.\n";
	cout << "5. Exit\n";
	cout << "Selection: ";
	cin >> input;
	switch (input) {
	case 1:           
		chooseGirl(input);
		break;
	case 2:            
		talk(input);
		break;
	case 3:            
		findGirl();
		break;
	case 4:
		dateGirl();
		break;
	case 5:            
		cout << "Are you sure you wanna leave the ladies? ( ͡° ͜ʖ ͡°) \n";
		break;
	default:            
		cout << "Error, type what you see bruh, quitting.\n";
		break;
	}
	cin.get();
	return 0;
}