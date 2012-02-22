@interface Cell:
NSObject<NSCoding>
{
	NSInteger x, y;
	Color color;
}

@property NSInteger x, y;
@property Color color;
@end

@implementation Cell
@synthesize x, y, color;

-(Cell*)initWithXAndYAndColor:
(NSInteger) coordX :
(NSInteger)coordY :
(Color) c
{
	if(self = [super init])
	{
[self setX:coordX];
[self setY:coordY];
[self setColor:c];
	}
	return self;
}
-(char*) getColor
{
return [color_toString[color] cStringUsingEncoding: NSMacOSRomanStringEncoding];
}
-(NSString*) description
{
return [[NSString alloc] initWithFormat: @"Cell@(%i,%i,%s)", x, y, [color_toString[color] cStringUsingEncoding: NSMacOSRomanStringEncoding]];
}
-(void) display
{
printf("%s", [color_toString[color] cStringUsingEncoding: NSMacOSRomanStringEncoding]);
}
-(id)initWithCoder:
(NSCoder*) decoder
{
	if(self = [super init])
	{
x = [decoder decodeIntForKey:@"x"];
y = [decoder decodeIntForKey:@"y"];
color = [decoder decodeIntForKey:@"color"];
	}
	return self;
}
-(void)encodeWithCoder:
(NSCoder*) encoder
{
[encoder encodeInt:x forKey:@"x"];
[encoder encodeInt:y forKey:@"y"];
[encoder encodeInt:color forKey:@"color"];
}
@end