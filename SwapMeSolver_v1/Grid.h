#define grid(col,row) [[grid objectAtIndex: col] objectAtIndex: row]

@interface Grid:
NSObject
{
	NSMutableArray* grid;
}
@property(nonatomic, retain) NSMutableArray* grid;
@end

@implementation Grid
@synthesize grid;
-(Grid*) init
{
	if(self = [super init])
	{
		NSMutableArray *grid_ = [[[NSMutableArray alloc] init] autorelease];
		NSMutableArray *row = [[[NSMutableArray alloc] init] autorelease];
		for(int x = 0; x < 6; x++)  	// col
		{
[grid_ addObject:[NSMutableArray array]];
row = [grid_ objectAtIndex:x];
			for(int y = 0; y < 7; y++)  	// row
[row addObject:[[Cell alloc] initWithXAndYAndColor: x : y : BLACK]];
		}
[self setGrid:grid_];
	}
	return self;
}
-(Grid*) initWithGrid:
(NSMutableArray*) grid
{
	if(self = [super init])
	{
[self setGrid:grid];
	}
	return self;
}
-(void) config
{
[grid(1, 0) setColor: GREEN];
[grid(1, 1) setColor: RED];
[grid(2, 0) setColor: BLUE];
[grid(2, 1) setColor: GREEN];
[grid(2, 2) setColor: PINK];
[grid(2, 3) setColor: BLUE];
[grid(2, 4) setColor: RED];
[grid(2, 5) setColor: GREEN];
[grid(3, 0) setColor: PINK];
[grid(3, 1) setColor: BLUE];
[grid(3, 2) setColor: PINK];
[grid(3, 3) setColor: RED];
}
-(void) display
{
	for(int y = 6; y >= 0; y--)  		// row
	{
		for(int x = 0; x < 6; x++)		// col
			[grid(x, y) display];
		printf("\n");
	}
}
-(NSMutableArray*) deepCopy {
NSMutableArray *temp;
[[NSUserDefaults standardUserDefaults] setObject: [NSKeyedArchiver archivedDataWithRootObject:grid] forKey: @"savedArray"];
NSUserDefaults *currentDefaults = [NSUserDefaults standardUserDefaults];
NSData *dataRepresentingSavedArray = [currentDefaults objectForKey:@"savedArray"];
if(dataRepresentingSavedArray)
{
	NSArray *oldSavedArray = [NSKeyedUnarchiver unarchiveObjectWithData:dataRepresentingSavedArray];
	temp = oldSavedArray ? [[NSMutableArray alloc] initWithArray : oldSavedArray]
	: [[NSMutableArray alloc] init];
}
	return temp;
}
-(NSInteger) getHeight:
(NSInteger) col
{
	for(int y = 6; y >= 1; y--)  	// row
		if([grid(col, y) color] != BLACK)
			return y + 1;
	return 0;
}
-(void) collapseCol:
(MyMove*) move
{
	Cell* cell = [move cell];
	for(int y = [cell y]; y < 6; y++)  	// row
[grid([cell x], y) setColor: [grid([cell x], y + 1) color]];
}
-(NSMutableArray*) makeMove:
(MyMove*) move
{
	// x: col; y: row
	NSInteger newCol, newRow;
	Cell* cell = [move cell];
	switch([move dir])
	{
	case LEFT:
		if([cell x] > 0)
		{
NSLog(@"LEFT (current,color,col,ht):(%u,%s,%u,%u)", [cell x], [cell getColor], [cell x] - 1, [self getHeight : [cell x] - 1]);
			newCol = [cell x] - 1;
newRow = [self getHeight : [cell x] - 1];
[grid(newCol, newRow) setColor: [cell color]];
[self collapseCol:move];
		}
		break;
	case RIGHT:
		if([cell x] < 5)
		{
NSLog(@"RIGHT (current,color,col,ht):(%u,%s,%u,%u)", [cell x], [cell getColor], [cell x] + 1, [self getHeight : [cell x] + 1]);
			newCol = [cell x] + 1;
newRow = [self getHeight : [cell x] + 1];
[grid(newCol, newRow) setColor: [cell color]];
[self collapseCol:move];
		}
		break;
	default:
		break;
	}

	return grid;
}
-(NSMutableArray*) getMoves
{
	NSMutableArray* moves = [[[NSMutableArray alloc] init] autorelease];
	for(int y = 6; y >= 0; y--)
	{
		for(int x = 0; x < 6; x++)
		{
			// no possible move if cell unoccupied
			if([grid(x, y) color] == BLACK) continue;

			if(x < 5)
				if([grid(x+1, y) color] == BLACK)
[moves addObject:[[MyMove alloc] initWithCellAndDir: grid(x, y) : RIGHT]];

			if(x > 0)
				if([grid(x-1, y) color] == BLACK)
[moves addObject:[[MyMove alloc] initWithCellAndDir: grid(x, y) : LEFT]];
		}
	}
	return moves;
}
-(void) dealloc
{
	for(int x = 0; x < 6; x++)
		for(int y = 0; y < 7; y++)
			[grid(x, y) release];
	[super dealloc];
}
@end