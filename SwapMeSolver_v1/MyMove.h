#define grid(col,row) [[grid objectAtIndex: col] objectAtIndex: row]

@interface MyMove:
NSObject
{
	Cell* cell;
	moveDir dir;
}
@property(nonatomic, retain) Cell *cell;
@property moveDir dir;
@end

@implementation MyMove
@synthesize cell, dir;
-(MyMove*) initWithCellAndDir:
(Cell*) c :
(moveDir) d
{
	if(self = [super init])
	{
[self setCell:c];
[self setDir:d];
	}
	return self;
}
-(NSString*) description
{
return [[NSString alloc] initWithFormat: @"Move@(%s,%s)", [[cell description] cStringUsingEncoding: NSMacOSRomanStringEncoding], [move_toString[dir] cStringUsingEncoding: NSMacOSRomanStringEncoding]];
}
-(void)dealloc
{
	[cell release];
	[super dealloc];
}
@end