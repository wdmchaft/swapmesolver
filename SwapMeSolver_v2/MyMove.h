#import "Cell.h"
#import "Enum.h"

@interface MyMove:
NSObject
{
	Cell* cell;
	MoveDir dir;
}
@property(nonatomic, retain) Cell *cell;
@property MoveDir dir;

- (MyMove*) initWithCellAndDir:
(Cell*) c :
(MoveDir) d;
- (NSString*) description;
- (void) dealloc;
@end