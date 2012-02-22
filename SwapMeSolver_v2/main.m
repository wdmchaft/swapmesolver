#import "main.h"

int main(int argc, const char * argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	Grid* grid = [[Grid alloc] init];
	// board state
NSArray *config = [NSArray arrayWithObjects:
	                   @"1,0,G", @"1,1,R",
	                   @"2,0,B", @"2,1,G", @"2,2,P", @"2,3,B", @"2,4,R", @"2,5,G",
	                   @"3,0,P", @"3,1,B", @"3,2,P", @"3,3,R",
	                   nil];
	// init grid by filling w/ board state
[grid setup:config];
	// show this grid
	[grid display];

	// construct a list of all possible moves from this state - recursive function
	BOOL success = [grid iterate: 3];	// initial depth

	// DEBUG //
	/*
	NSMutableArray* moves = [grid getMoves];
	NSSortDescriptor *moveSorter = [[NSSortDescriptor alloc] initWithKey: @"cell" ascending: YES];
	[moves sortUsingDescriptors:[NSArray arrayWithObject:moveSorter]];
	NSLog(@"%@ %d", moves, [moves count]);

	for (int x=0; x<ROW_WIDTH; x++)
		NSLog(@"%d",[grid getHeight:x]);

	config = [NSArray arrayWithObjects:
			   @"1,0,G", @"1,1,R",
			   @"2,1,G", @"2,2,R",
			   @"3,0,P", @"3,1,B", @"3,2,P", @"3,3,R",
			   nil];
	[grid setup:config];
	[grid display];
	// collapse all columns
	for(int x = 0; x <= ROW_WIDTH; x++)
		[grid collapseCol: x];
	[grid display];

	[grid makeMove: [[MyMove alloc] initWithCellAndDir: [[Cell alloc] initWithXAndYAndColor: 1 : 1 : RED] : RIGHT]];
	[grid display];
	 */

	[pool drain];
	return 0;
}