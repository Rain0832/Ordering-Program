#include<stdio.h>

void showMenu();                                         //ÏÔÊ¾²Ëµ¥
double calculateDiscount(double prePrice);
double calculatFreight(double weight);
void confirmTheInformation(double weight, double prePrice);
void showOrderInformationPre(char itemName[]);
void showOrderInformationFin(char itemName[], double total);

int main(void)
{
	char c;
	double totalArtchoke = 0, totalBeet = 0, totalCarrot = 0, buffer = 0;
	double weight, prePrice, finPrice;
	showMenu();
	do {
		scanf("%c", &c);
		switch (c)
		{
		case 'a':
			showOrderInformationPre("Artchoke");
			scanf("%lf", &buffer);
			totalArtchoke = totalArtchoke + buffer;
			getchar();
			showOrderInformationFin("Artchoke", totalArtchoke);
			break;
		case 'b':
			showOrderInformationPre("Beet");
			scanf("%lf", &buffer);
			totalBeet = totalBeet + buffer;
			getchar();
			showOrderInformationFin("Beet", totalBeet);
			break;
		case 'c':
			showOrderInformationPre("Carrot");
			scanf("%lf", &buffer);
			totalCarrot = totalCarrot + buffer;
			getchar();
			showOrderInformationFin("Carrot", totalCarrot);
			break;
		case 'q':
			break;
		default:
			printf("Invalid input.\n");
		}
	} while (c!='q');
	weight = totalArtchoke + totalBeet + totalCarrot;
	prePrice = totalArtchoke * 2.05 + totalBeet * 1.15 + totalCarrot * 1.09;
	confirmTheInformation(weight, prePrice);
	finPrice = prePrice + calculatFreight(weight) - calculateDiscount(prePrice);
	printf("Then the final price is %lf %s.\n", finPrice, finPrice == 1 ? "Dollar" : "Dollars");
	return 0;
}

void showMenu()
{
	printf("This is a program for ABC Mail Order Grocery Store.\n");
	printf("You can order some items by typing.\n");
	printf("Typing 'a' for 'Artchoke'.\n");
	printf("Typing 'b' for 'Beet'.\n");
	printf("Typing 'c' for 'Carrot'.\n");
	printf("Typing 'q' for 'End your order'.\n");
	printf("You can repeat typing same alphas, that means add to your existing bill.\n");
	printf("Introduction:\n");
	printf("ABC Mail Order Grocery Store now selling artchokes, beets and carrots.\n");
	printf("Before add the freight, if your order total price reach $ 100, we will give you a discount for 5 %%.\n");
	printf("Freight and Packing Charges:\n");
	printf("We will charge $ 6.5 for the order that total weight less than or equal to 5 pounds.\n");
	printf("We will charge $ 14 for the order that total weight less than or equal to 20 pounds, but more than 5 pounds.\n");
	printf("We will charge more $ 0.5 per pound based on the $14, for the order that total weight more than 20 pounds.\n");
	printf("If you have any question:\n");
	printf("Call tel-6187265 (weekday)\n");
	printf("Send email-1178263@163.com (weekday)\n");
	printf("Hope you have a good shopping!\n");
	printf("Edited by ABC Mail Order Grocery Store\n");
}

double calculateDiscount(double prePrice) 
{
	double discount;
	if (prePrice >= 100)
	{
		discount = prePrice * 0.05;
	}
	else
	{
		discount = 0;
	}
	printf("So, you have %lf discount.\n", discount);
	return discount;
}

double calculatFreight(double weight)
{
	double freight;
if (weight <= 5)
{
	freight = 6.5;
}
else if (weight > 5 && weight <= 20)
{
	freight = 14;
}
else
{
	freight = 14 + (weight - 20) * 0.5;
}
printf("So, you have %lf freight.\n", freight);
return freight;
}

void confirmTheInformation(double weight, double prePrice)
{
	printf("So, you end your shopping just now.\n");
	printf("The total weight of the items %s %.2lf %s.\n", weight == 1 ? "is" : "are", weight, weight == 1 ? "Dollar" : "Dollars");
	printf("The previous price is %.2lf %s.\n", prePrice, prePrice == 1 ? "Dollar" : "Dollars");
}

void showOrderInformationPre(char itemName[])
{
	printf("Welcome to %s Area.\n", itemName);
	printf("Now you can type how many %s you want to order.(pound)\n", itemName);
}

void showOrderInformationFin(char itemName[],double total)
{
	printf("Adding successfully.\n");
	printf("Now your order have %.2lf %s %s.\n", total, total == 1 ? "pound" : "pounds", itemName);
}