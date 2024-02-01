#include <iostream>   
#include <sstream>   
#include <string>   
#include <ctime>   // This is a library for accessing date and time  
#include <cstdlib>
/*using the system function from the cstdlib library enables you to execute
operating system-specific commands in a way that promotes portability.
This means your code can run on different operating systems without requiring changes.*/

struct PersonalDonor // We use this struct to store personal information
{
	std::string Name; // Personal donor's first name
	std::string lastName; // Personal donor's last name
	std::string email; // Personal donor's email address
	std::string phone; // Personal donor's phone number
};

struct CorporateDonor // We use this struct to store corporate information
{
	std::string name; // Corporate donor's name
	std::string email; // Corporate donor's email address
	std::string phone; // Corporate donor's phone number
	std::string address; // Corporate donor's address
	std::string fax; // Corporate donor's fax number
};

// It is a struct that includes year, month and day about expire date and delivery date
struct Date {

	int expireDay;
	int expireMonth;
	int expireYear;
	int delivery_year;
	int delivery_month;
	int delivery_day;

};

//In this section we define food related information.
struct Food
{
	std::string donationCountry[6]{ "Germany","USA","England","Turkey","Japan","Russia" };
	std::string selectedCountry;
	std::string foodType;
	std::string foodName;
	std::string amountFood;
	Date expireDate; // a struct inside a struct
	Date delivery{}; // a struct inside a struct
};


// This structure holds the necessary information for one-time money donation transaction.
struct MoneyOnce
{
	std::string donationCountry[6]{ "Germany","USA","England","Turkey","Japan","Russia" }; // The string "donationCountry" contains the names of the countries to which donations can be made.
	std::string selectedCountry;                                                           // The variable "selectedCountry" holds the country selected by the user.
	int quantityOfTheDonation{};                                                             // The variable "quantityOfTheDonation" holds the donation amount.
	std::string donationCurrency[6]{ "EUR","USD","GBP","TRY","JPY","RUB" };                // The string "donationCurrency" contains the currencies users can choose for donations.
	std::string selectedCurrency;                                                          // The variable "selectedCurrency" holds the currency selected by the user.

};


// This struct holds the necessary information for a recurring fundraiser once a month.
struct MoneyMonthly

{
	std::string donationCountry[6]{ "Germany","USA","England","Turkey","Japan","Russia" }; // The string "donationCountry" contains the names of the countries to which donations can be made.
	std::string selectedCountry;                                                           // The variable "selectedCountry" holds the country selected by the user.
	int  quantityOfTheDonation{};                                                            // The variable "quantityOfTheDonation" holds the donation amount.
	std::string donationCurrency[6]{ "EUR","USD","GBP","TRY","JPY","RUB" };                // The string "donationCurrency" contains the currencies the user can choose for donation.
	std::string selectedCurrency;                                                          // The variable "selectedCurrency" holds the currency selected by the user.
	int monthDay{};                                                                          // The variable "monthDay" is used to select which day of each month the donation will be made.
};

// Function to clear the console screen
void clearConsole()
{
	std::cout << "\nPress enter to continue..."; // Prompting user to press enter
	std::cin.ignore(); // Ignoring any characters in the input buffer
	std::cin.get(); // Waiting for the user to press enter
	system("cls"); // Clearing the console screen
}


void addPersonalDonor(PersonalDonor& donor) // Function to take user input for personal donor
{
	std::cout << "Please enter your name: ";
	std::getline(std::cin, donor.Name); // Get the personal donor's first name
	std::cout << "Please enter your last name: ";
	std::getline(std::cin, donor.lastName); // Get the personal donor's last name
	std::cout << "Please enter your email address: ";
	std::getline(std::cin, donor.email); // Get the personal donor's email address
	std::cout << "Please enter your phone number: ";
	std::getline(std::cin, donor.phone); // Get the personal donor's phone number
}

void addCorporateDonor(CorporateDonor& donor) // Function to take user input for corporate donor
{
	std::cout << "Please enter your corporation's name: ";
	std::getline(std::cin, donor.name); // Get the corporate donor's name
	std::cout << "Please enter your email address: ";
	std::getline(std::cin, donor.email); // Get the corporate donor's email address
	std::cout << "Please enter your phone number: ";
	std::getline(std::cin, donor.phone); // Get the corporate donor's phone number
	std::cout << "Please enter your corporation's address: ";
	std::getline(std::cin, donor.address); // Get the corporate donor's address
	std::cout << "Please enter your corporation's fax number: ";
	std::getline(std::cin, donor.fax); // Get the corporate donor's fax number
}

// This function adds a money donation transaction based on the "MoneyOnce" struct.
// The function retrieves the donor country, donation amount and currency selected by the user.
void addMoney(MoneyOnce& DonationOnce)  // function overloading

{

againCountry1:

	std::cout << "Please enter the country which you donate to: " << "\n";     //We have enabled the user to select the countries by using
	std::cout                                                                  //the array defined in the structure section.*/
		<< "Please do not use non - digit characters.It can cause some problems.\n"
		<< "Press 1 for Germany\n"
		<< "      2 for USA\n"
		<< "      3 for England\n"
		<< "      4 for Turkey\n"
		<< "      5 for Japan\n"
		<< "      6 for Russia\n";

	int choice;
	std::cout << "Selection: ";
	std::cin >> choice;
	std::cout << "\n";
	std::cout << "-------------------------------------------------------------\n";

	//Here we have defined an array containing 6 countries. If the data entered by the user is one of these 6 countries, the next question is passed.
	//If the entered data is from other than these 6 countries, the user is asked to enter the input again.
	if (choice >= 1 && choice <= 6)
	{
		DonationOnce.selectedCountry = DonationOnce.donationCountry[choice - 1];
		// The variable "DonationOnce.selectedCountry" holds the country selected by the user.
	}


	else
	{

		std::cout << "Wrong selection. Please try again.\n";
		goto againCountry1;
	}
againCurrency1:
	std::cout << "Please choose your country currency:\n"
		<< "Please do not use non - digit characters.It can cause some problems.\n"
		<< "Press 1 for EUR\n"
		<< "      2 for USD\n"
		<< "      3 for GBP\n"
		<< "      4 for TRY\n"
		<< "      5 for JPY\n"
		<< "      6 for RUB\n";
	int choice2;
	std::cout << "Selection: ";
	std::cin >> choice2;
	std::cout << "-------------------------------------------------------------\n";
	std::cout << "\n";

	//Here we have defined an array containing 6 currencies. If the data entered by the user is one of these 6 currencies, the next question is passed.
	//If the entered data is other than these 6 currencies, the user is asked to enter the input again.
	if (choice2 >= 1 && choice2 <= 6) {

		DonationOnce.selectedCurrency = DonationOnce.donationCurrency[choice2 - 1];
		// The variable "DonationOnce.selectedCurrency" holds the currency of the user's choice.
	}


	else {
		std::cout << "Wrong selection. Please try again.\n";
		goto againCurrency1;
		//The "goto" statement allows the user to return to the same menu when a wrong choice is made, until they make the right choice.
	}

	std::cout << "Please enter the amount of the money will you donate: ";
	std::cin >> DonationOnce.quantityOfTheDonation;
	// The variable "DonationOnce.quantityOfTheDonation" holds the donation amount entered by the user.

	std::cout << "\nYou are directed to the payment page.";
	//This function directs the user to the payment page.
}

// This function adds a money donation transaction based on the "MoneyMonthly" struct.
// The function retrieves the donor country, donation amount and currency selected by the user.
void addMoney(MoneyMonthly& DonationMonthly) // function overloading

{

again3:

	std::cout << "Please enter the country which you donate to: " << "\n"
		<< "Please do not use non - digit characters.It can cause some problems.\n"
		<< "Press 1 for Germany\n"
		<< "      2 for USA\n"
		<< "      3 for England\n"
		<< "      4 for Turkey\n"
		<< "      5 for Japan\n"
		<< "      6 for Russia\n";
	int choice3;
	std::cout << "Selection: ";
	std::cin >> choice3;
	std::cout << "\n";
	std::cout << "-------------------------------------------------------------\n";

	//Here we have defined an array containing 6 countries. If the data entered by the user is one of these 6 countries, the next question is passed.
	//If the entered data is from other than these 6 countries, the user is asked to enter the input again.
	if (choice3 >= 1 && choice3 <= 6)
	{

		DonationMonthly.selectedCountry = DonationMonthly.donationCountry[choice3 - 1];
		// The variable "DonationMonthly.selectedCountry" holds the country selected by the user.
	}

	else
	{

		std::cout << "Wrong selection. Please try again.\n";
		goto again3;

	}

again4:

	std::cout << "Please enter your country currency: " << "\n"
		<< "Please do not use non - digit characters.It can cause some problems.\n"
		<< "Press 1 for EUR\n"
		<< "      2 for USD\n"
		<< "      3 for GBP\n"
		<< "      4 for TRY\n"
		<< "      5 for JPY\n"
		<< "      6 for RUB\n";
	int choice4;
	std::cout << "Selection: ";
	std::cin >> choice4;
	std::cout << "-------------------------------------------------------------\n";
	std::cout << "\n";

	//Here we have defined an array containing 6 currencies. If the data entered by the user is one of these 6 currencies, the next question is passed.
	//If the entered data is other than these 6 currencies, the user is asked to enter the input again.

	if (choice4 >= 1 && choice4 <= 6)
	{

		DonationMonthly.selectedCurrency = DonationMonthly.donationCurrency[choice4 - 1];
		// The variable "DonationMonthly.selectedCurrency" holds the currency of the user's choice.
	}

	else
	{
		std::cout << "Wrong selection. Please try again.\n";
		goto again4;
	}

	std::cout << "Please enter the amount of the money will you donate monthly:\n"
		<< "Please do not use non-digit characters.It can cause some problems.\n";
	std::cout << "Money quantity: ";
	std::cin >> DonationMonthly.quantityOfTheDonation;
	std::cout << "\n";
	// The variable "DonationMonthly.quantityOfTheDonation" holds the donation amount entered by the user.                                                
	std::cout << "Please enter which day of each month you would like to donate:" << "\n";
	std::cout << "Please enter a number between 1 and 28.\n(Otherwise that can cause some problems):\n";
	std::cout << "The day: ";
againDate:
	std::cin >> DonationMonthly.monthDay;
	// The variable "DonationMonthly.monthDay" holds the user on which day of each month to donate.
	if (DonationMonthly.monthDay >= 1 && DonationMonthly.monthDay <= 28) {
		std::cout << "The day you chose has been accepted.\n";

	}
	else
	{
		std::cout << "-------------------------------------------------------------\n";
		std::cout << "The day you entered could not be accepted. " << "\n\n"
			<< "Please enter a number between 1 - 28: ";
		goto againDate;
	}
	std::cout << "\nYou are directed to the payment page.";
}
void addFood(Food& food); // We defined our function above for overloading.
void addFood(std::string& select) { //In this section, the function that is called when it wants to add a food type other than the choices presented below has been created.Function overloading.

	std::cout << "Please enter the type of food item: ";
	std::cin.ignore();// This code clears the previously entered entry.
	std::getline(std::cin, select);


}

void addTypeofthefooditems(std::string& selection) { //In this function, we printed the food types on the screen and set up the if-else loop to be used when choosing the food types.
	// By using Again, we made sure that the same question is asked again when he makes the wrong choice.
again:
	std::cout <<
		"Please select the type of food item (Enter capital letters between \"A\"and \"M\"): \n"
		"A)Meat, Chicken, Fish etc. \n"
		"B)Milk and Dairy Products\n"
		"C)Egg\n"
		"D)Legumes \n"
		"E)Canned Foods\n"
		"F)Frozen Foods \n"
		"G)Bakery Products\n"
		"H)Bread and Cereals \n"
		"I)Dried Foods \n"
		"J)Vegetables and Fruits\n"
		"K)Oil\n"
		"L)Water \n"
		"M)Other Food Types \n";

	std::cout << "Selection: ";
	std::cin >> selection;
	if (selection == "A") {
		selection = "Meat, Chicken, Fish etc.";
		std::cout << "-------------------------------------------------------------\n";
	}

	else if (selection == "B") {
		selection = "Milk and Dairy Products";
		std::cout << "-------------------------------------------------------------\n";
	}
	else if (selection == "C") {
		selection = "Egg";
		std::cout << "-------------------------------------------------------------\n";
	}
	else if (selection == "D") {
		selection = "Legumes";
		std::cout << "-------------------------------------------------------------\n";
	}

	else if (selection == "E") {
		selection = "Canned Foods";
		std::cout << "-------------------------------------------------------------\n";
	}

	else if (selection == "F") {
		selection = "Frozen Foods";
		std::cout << "-------------------------------------------------------------\n";
	}
	else if (selection == "G") {
		selection = "Bakery Products";
		std::cout << "-------------------------------------------------------------\n";
	}
	else if (selection == "H") {
		selection = "Bread and Cereals";
		std::cout << "-------------------------------------------------------------\n";
	}
	else if (selection == "I") {
		selection = "Dried Foods";
		std::cout << "-------------------------------------------------------------\n";
	}
	else if (selection == "J") {
		selection = "Vegetables and Fruits";
		std::cout << "-------------------------------------------------------------\n";
	}
	else if (selection == "K") {
		selection = "Oil";
		std::cout << "-------------------------------------------------------------\n";
	}

	else if (selection == "L") {
		selection = "Water";
		std::cout << "-------------------------------------------------------------\n";
	}
	else if (selection == "M") {
		addFood(selection);
		std::cout << "-------------------------------------------------------------\n";
	}
	else {
		std::cout << "Wrong selection. Please try again.\n";
		std::cout << "-------------------------------------------------------------\n";
		goto again;
	}

}

void addFood(Food& food) { /*In this function, we called the function that determines the type of food and we created this function to learn the name of the food,
	from which country the food will be sent, how much of the food will be donated, the expiry date of the food and the delivery date.*/
again5:

	std::cout << "Please enter the country which you donate to: " << "\n";       //We have enabled the user to select the countries by using the array defined in the structure section.
	std::cout << "ATTENTION! If you log in other than the number, you will have to log in to the system from the beginning." << "\n"
		<< "Press 1 for Germany\n"
		<< "      2 for USA\n"
		<< "      3 for England\n"
		<< "      4 for Turkey\n"
		<< "      5 for Japan\n"
		<< "      6 for Russia\n";

	int choice;
	std::cout << "Selection: ";
	std::cin >> choice;
	std::cout << "\n";
	std::cout << "-------------------------------------------------------------\n";
	if (choice >= 1 && choice <= 6)
	{
		food.selectedCountry = food.donationCountry[choice - 1];
	}

	else
	{
		std::cout << "Wrong selection. Please try again.\n";                  //Again5 is used to run the loop from the beginning when the wrong selection is made.
		goto again5;
	}

	addTypeofthefooditems(food.foodType);                   //The function(Type of the food items) was called.


	std::cout << "Please enter the name of the food item: ";      //The user is prompted to enter the name of the food.
	std::cin.ignore(); // This code clears the previously entered entry.
	std::getline(std::cin, food.foodName);
	std::cout << "-------------------------------------------------------------\n";
	std::cout << "Please enter the amount of donated food in kg/L/packet/number.\n"
		<< "(Please enter just number): "; //The user is asked to enter how much the food will donate.
	// This code clears the previously entered entry.
	std::getline(std::cin, food.amountFood);
	std::cout << "-------------------------------------------------------------\n";
invalid:
	std::cout << "Please enter as number  the year of expiration date (enter as number): ";     //The user is asked to enter the expiry date of the food (year, month and day are asked as separate questions).
	std::cin >> food.expireDate.expireYear;                                                     // In this section, it is accessed the member of the struct inside the struct by using . (dot) 
	std::cout << "Please enter as number the month of expiration date (enter as number between 1-12): ";
	std::cin >> food.expireDate.expireMonth;
	std::cout << "Please enter as number the day of expiration date (enter as number between 1-30): ";
	std::cin >> food.expireDate.expireDay;

	std::time_t t = time(nullptr);        //These codes are written to access the computer's date information.
	std::tm today;
	localtime_s(&today, &t);
	int todayDay = today.tm_mday;           //These codes are written to define the day, month and year correctly.
	int todayMonth = today.tm_mon + 1;
	int todayYear = today.tm_year + 1900;

	//If the expiration date entered in the if-else loop has passed (before today's date), the food name, how much the food will be donated, and the expiration date are requested.

	if (food.expireDate.expireYear < todayYear || (food.expireDate.expireYear == todayYear && food.expireDate.expireMonth < todayMonth) || (food.expireDate.expireYear == todayYear && food.expireDate.expireMonth == todayMonth && food.expireDate.expireDay < todayDay)) {

		std::cout << "You can't donate food because the expiration date has passed.\n" << std::endl;
		std::cout << "-------------------------------------------------------------\n";
		goto invalid;
	}
	//If the correct expiration date is written, the delivery date is asked (year, month and day are asked in separate questions).
	else {
		std::cout << "You can donate food that has not passed its expiration date." << std::endl;

	invalid2:
		std::cout << "-------------------------------------------------------------\n";
		std::cout << "Please enter as number the year of deliver date (enter as number ): "; // In this section, it is accessed the member of the struct inside the struct by using . (dot) 
		std::cin >> food.delivery.delivery_year;
		std::cout << "Please enter as number the month of deliver date (enter as number between 1-12): ";
		std::cin >> food.delivery.delivery_month;
		std::cout << "Please enter as number the day of delivery date (enter as number between 1-30): ";
		std::cin >> food.delivery.delivery_day;


		//Checks whether the delivery date is before or after the expiration date. After the expiration date, it asks for a re-delivery date.
		if (food.delivery.delivery_year > food.expireDate.expireYear || (food.delivery.delivery_year == food.expireDate.expireYear && food.delivery.delivery_month > food.expireDate.expireMonth) || (food.delivery.delivery_year == food.expireDate.expireYear && food.delivery.delivery_month == food.expireDate.expireMonth && food.delivery.delivery_day > food.expireDate.expireDay)) {

			std::cout << "You can't deliver the food on this date because the delivery date is after the expiry date.\n" << "Please enter a new delivery date." << std::endl;

			goto invalid2;
		}

		else {
			//Checks whether the delivery date is before or after today's date. If it is before today's date, it asks for a re-delivery date.

			while (food.delivery.delivery_year < todayYear || (food.delivery.delivery_year == todayYear && food.delivery.delivery_month < todayMonth) || (food.delivery.delivery_year == todayYear && food.delivery.delivery_month == todayMonth && food.delivery.delivery_day < todayDay)) {
				std::cout << "You entered a past date.\n" << "Please enter a new delivery date." << std::endl;
				goto invalid2;
			}
			std::cout << "-------------------------------------------------------------\n";
			std::cout << "You can deliver the food on" << " " << food.delivery.delivery_year << "/" << food.delivery.delivery_month << "/" << food.delivery.delivery_day << std::endl;

		}
	}
}

// This a function that displays on the screen the amount of the food, the name of the food and country where is sent that have donated
void displayDonationFood(Food* ptr2) // The parameter of the function is a struct 
{
	std::cout << "You have donated " << ptr2->amountFood << " kg/L/packet/number of " << ptr2->foodName << " from " << ptr2->selectedCountry << "." << std::endl;
	// I access the members of the Food struct by using pointer
	std::cout << "Thanks for your Donation...\n";
}

//This a a function that ddisplays on the screen  and the country where is sent that has donated once. 
void displayDonationMoney(MoneyOnce* ptr2) // Function overloading  
{
	std::cout << "You have donated " << ptr2->quantityOfTheDonation << ptr2->selectedCurrency << " amount of money once from " << ptr2->selectedCountry << "." << std::endl;
	// I access the members of the MoneyOnce struct by using pointer
	std::cout << "Thanks for your Donation...\n";
}

// This is a function that displays on the screen the quantity of the money and the country where is sent that has donated monthly and also it shows the day of the every month
void displayDonationMoney(MoneyMonthly* ptr2)  // Function overloading 
{
	std::cout << "You will donate " << ptr2->quantityOfTheDonation << ptr2->selectedCurrency << " on " << ptr2->monthDay << " of the every month from " << ptr2->selectedCountry << "." << std::endl;
	// I access the members of the MoneyMonthly  struct by using pointer
	std::cout << "Thanks for your Donation...\n";
}

bool cardNumber(int number) //**Kadir -> Function to check if the card number is valid.
{
	if (number >= 1000 && number <= 9999) {
		return true;
	}
	return false;
}

void cardDonation(int cardRow, int cardColumns) // Function to process card donation.
{
	std::string expirationDate;
	std::string cvvCode;
	int cardNumbers[1][4];

	std::cout << "Please enter your card numbers ([4]-[4]-[4]-[4]): "; // Prompt the user to enter card numbers.
	for (int a = 0; a < cardRow; a++) {
		for (int b = 0; b < cardColumns; b++) {
			std::cin >> cardNumbers[a][b];
			if (!cardNumber(cardNumbers[a][b])) // Check if the entered card number is valid.
			{
				std::cout << "* Please re-enter your card number.\n"
					<< "* Make sure you have entered your card information correctly. "
					<< std::endl;
				std::cout << "Please enter your card numbers: ";
				b--; // Decrease the value of 'b' to re-enter the invalid number.
			}
		}
	}
	std::cout << "Please enter expiration date of your card (MM-YY): ";  // Prompt the user to enter expiration date and CVV code.
	std::cin >> expirationDate;
	std::cout << "Please enter your CVV code (xxx): ";
	std::cin >> cvvCode;

	std::cout << std::endl << "Card numbers you have entered: ";
	for (int c = 0; c < cardRow; c++)  // Display the entered card numbers.
	{
		for (int d = 0; d < cardColumns; d++) {
			std::cout << cardNumbers[c][d] << " ";
		}
	}
	std::cout << std::endl << "Expiration Date:  " << expirationDate << std::endl;
	std::cout << "CVV code: " << cvvCode << std::endl;
	std::cout << "Thanks for your donation." << std::endl;

}//Payment Function

int main()
{

	std::string donorType;
againDonor:
	std::cout << "If you are a personal donor please press 1 or  a corporate donor press 2:";
	std::getline(std::cin, donorType); //We used getline so that it does not give an error if more than one character is entered in the user input.

	/* We use if block because of select one of the user type.
	If the user select a different type of character then the else function returned back to question line and repeat .*/
	if (donorType == "1")
	{
		PersonalDonor donor; // Create a personal donor object
		addPersonalDonor(donor); // Call the function to input personal donor information
		clearConsole();
	}
	else if (donorType == "2")
	{
		CorporateDonor donor; // Create a corporate donor object
		addCorporateDonor(donor); // Call the function to input corporate donor information
		clearConsole();
	}
	else
	{
		std::cout << "You entered an invalid donor type. Please choose one of the provided options.\n";
		goto againDonor; // If an invalid donor type is entered, repeat the question
	}

	const int cardRow = 1;
	const int cardColumns = 4;

	std::string donationTime;
	std::string donationType;
againDonation:

	std::cout << "Will you donate food or money?\nIf you donate food press 1 or money press 2 : ";
	std::cin >> donationType;
	std::cout << "-------------------------------------------------------------\n";
	std::cout << "\n";



	if (donationType == "1")
	{
		Food food; //Here it passes to the food function.
		Food selection;
		addFood(food);
		clearConsole();
		displayDonationFood(&food); // Here,the function that displays food is invoked  by passing address of the Food Struct.
	}
	else if (donationType == "2")
	{

		while (true)
		{
			std::string donationTime;
			std::cout << "Will you donate money once or monthly?\nfor once press 1; for monthly press 2: ";
			std::cin >> donationTime;
			std::cout << "-------------------------------------------------------------\n";
			std::cout << "\n";

			if (donationTime == "1")
			{
				MoneyOnce MoneyOnce;
				addMoney(MoneyOnce);
				clearConsole();
				cardDonation(cardRow, cardColumns); // Call the card donation function.
				clearConsole();
				displayDonationMoney(&MoneyOnce); // Here, the function that displays money have donated once is invoked by passing address of the MoneyOnce Struct.
				break;
			}
			else if (donationTime == "2")
			{
				MoneyMonthly MoneyMonthly;
				addMoney(MoneyMonthly);
				clearConsole();
				cardDonation(cardRow, cardColumns); // Call the card donation function again.
				clearConsole();
				displayDonationMoney(&MoneyMonthly); // Here, the function that displays money have donated monthly is invoked by passing address of the MoneyMonthly Struct.
				break;
			}
			else
			{
				std::cout << "You entered wrong donation time. Please just choose one of the two options mentioned.\n\n";
			}
		}

	}

	else
	{
		std::cout << "You entered wrong donation type. Please just choose one of the two options mentioned.\n \n";
		goto againDonation;
	}

}