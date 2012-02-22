#import "MyMove.h"

@implementation MyMove
@synthesize cell, dir;
-(MyMove*) initWithCellAndDir:
(Cell*) c :
(MoveDir) d
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
	return [[NSString alloc] initWithFormat: @"Move@(%@,%@)", [cell description], [Enum toMoveString:dir]];
}
-(void) dealloc
{
	[cell release];
	[super dealloc];
}
- (BOOL)isEqual:(id)other {
    if (other == self)
        return YES;
    if (!other || ![other isKindOfClass:[self class]])
        return NO;
    return [self isEqualToMove:other];
}
- (BOOL)isEqualToMove:(MyMove*)aMove {
    if (self == aMove)
        return YES;
    if (![(id)[self cell] isEqual:[aMove cell]])
        return NO;
	if ([self dir] != [aMove dir])
        return NO;
    return YES;
}
@end
