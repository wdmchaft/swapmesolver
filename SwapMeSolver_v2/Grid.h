#import "Cell.h"
#import "Enum.h"
#import "MyMove.h"
#define store(grid,x,y,c) [grid setObject: [[Cell alloc] initWithXAndYAndColor: x : y : c] \
								forKey: [NSNumber numberWithInt: y * ROW_WIDTH + x ]];

@interface Grid :
NSObject
{
	NSMutableDictionary* grid;
}
@property(nonatomic, retain) NSMutableDictionary* grid;

- (Grid*) init;
- (Grid*) initWithGrid:
(NSMutableDictionary*) grid;
- (NSMutableDictionary*) deepCopy;
- (void) setup:
(NSArray*) config;
- (void) display;
- (NSString*) description;
- (NSMutableArray*) getMoves;
- (NSInteger) getHeight:
(NSInteger) col;
-(void) collapseCol:
(NSInteger) col :
(NSInteger) startRow;
-(Cell*) makeMove:
(MyMove*) move;
- (BOOL) iterate :
(NSInteger) depth;
- (void) combine;
@end
