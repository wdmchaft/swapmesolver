#import "Enum.h"
#import "Cell.h"
#import "MyMove.h"
#import "Grid.h"

int main(int argc, const char * argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	NSString *red = [[NSString alloc] initWithString:@"Red"];
	NSString *twelve = [[NSString alloc] initWithString:@"12"];
	NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
	[dict setObject:red forKey:twelve];
	[dict setObject:red forKey:@"13"];
	[dict setValue:nil forKey:twelve];
	NSLog(@"%@", dict);
	NSLog(@"%u",[dict count]);
	NSArray *keys = [dict allKeys];
	for (NSString *key in keys)
		NSLog(@"%@ is %@",key, [dict objectForKey:key]);
	[dict release];
	
	Grid *gridObj = [[Grid alloc] init];
	[gridObj config];
	[gridObj display];
	NSMutableArray* moves = [gridObj getMoves];
	NSEnumerator* enumerator = [moves objectEnumerator];
	MyMove* move;
	while(move = [enumerator nextObject])
	{
Grid* gridNew = [[Grid alloc] initWithGrid: [gridObj deepCopy] ];
[gridNew makeMove:move];
		[gridNew display];
	}

	[pool drain];
	return 0;
}