/**
* Author: Cal Malone
*
* This program will help track mobile data usage
* for consumers by looking at number of Gigabytes in the plan
* and the total used so far to calculate an average per day
* to see if you are exceeding your average daily use.
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)   {

double totalNumberOfGB ;
int dayOfCycle ;
double numberOfGBUsed ;
double averageDailyUse ;
double suggestedDailyUse ;
int daysRemaining ;
int gigabytesLeftover ;
double suggestedRemainingUsage ;
int numberOfDays = 30 ;

if(argc != 4) {
  printf("Error: Not the correct number of command line arguments\n") ;
  exit(1) ;
}
  totalNumberOfGB = atoi(argv[1]) ;
  dayOfCycle = atoi(argv[2]) ;
  numberOfGBUsed = atoi(argv[3]) ;

  averageDailyUse = numberOfGBUsed / dayOfCycle ;
  suggestedDailyUse = totalNumberOfGB / numberOfDays ;
  daysRemaining = numberOfDays - dayOfCycle ;
  gigabytesLeftover = ((averageDailyUse * daysRemaining) + numberOfGBUsed)-totalNumberOfGB ;
  suggestedRemainingUsage = (totalNumberOfGB - numberOfGBUsed) / daysRemaining ;


  printf("%d Days Used, %d Days Remaining\n", dayOfCycle, daysRemaining) ;
  printf("Your Average Daily Use: %f GB/day\n", averageDailyUse) ;

  if(numberOfGBUsed > totalNumberOfGB) {
    printf("You have already exceeded your monthly limit with %d days left. Please contact your provider\n"
           "to explore other options.\n", daysRemaining) ;
  } else if(averageDailyUse > suggestedDailyUse) {
    printf("You are exceeding your suggested daily data usage (%f GB/day).\n", suggestedDailyUse) ;
    printf("Continuing this high usage, you'll exceed your data plan by %d GB.\n", gigabytesLeftover) ;
    printf("To stay below your data plan, use no more than %f GB/day.\n", suggestedRemainingUsage) ;
  } else if(averageDailyUse < suggestedDailyUse) {
    printf("You are below your suggested daily data usage (%f GB/day).\n", suggestedDailyUse) ;
    printf("To stay below your data plan, you can use up to %f GB/day.\n", suggestedRemainingUsage) ;
  } else if(averageDailyUse == suggestedDailyUse) {
    printf("You are right on track for your monthly data usage (%f GB/day).\n", suggestedDailyUse) ;
    printf("Continuing this data usage, you will use up all your data for the month.\n") ;
  }

  return 0;
}
