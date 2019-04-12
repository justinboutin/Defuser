#include "pch.h"
#include "../defuser/bomb.cpp"

// BOMB DEFUSED TESTS
TEST(TestBombDisposal, TestDefusalA) {
	Bomb bomb;

	bomb.lastWire = 'O';
	bomb.fourthRule('G');

	bool expectedValue = false;
	bool actualValue = bomb.exploded;
    EXPECT_EQ(expectedValue, actualValue);
}

TEST(TestBombDisposal, TestDefusalB) {
	Bomb bomb;
	bomb.fifthRule('O');

	bool expectedValue = false;
	bool actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);
}

// BOMB EXPLODED TESTS
TEST(TestBombExplosion, TestExplodeFirstRule) {
	Bomb bomb;

	bomb.firstRule('B');

	bool expectedValue = true;
	bool actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.firstRule('O');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.firstRule('G');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);
}

TEST(TestBombExplosion, TestExplodeSecondRule) {
	Bomb bomb;

	// Last wire cut was white
	bomb.lastWire = 'W';
	bomb.secondRule('R');

	bool expectedValue = true;
	bool actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.secondRule('O');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.secondRule('G');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	//last wire cut was red
	bomb.lastWire = 'R';
	bomb.secondRule('W');

	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.secondRule('O');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.secondRule('G');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);
}

TEST(TestBombExplosion, TestExplodeThirdRule) {
	Bomb bomb;

	// White wire cut then white wire cut.

	bomb.firstWire = 'W';
	bomb.lastWire = 'W';

	bomb.thirdRule('W');

	bool expectedValue = true;
	bool actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.thirdRule('R');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.thirdRule('O');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.thirdRule('G');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	// Red wire cut then red wire cut

	bomb.firstWire = 'R';
	bomb.lastWire = 'R';

	bomb.thirdRule('W');

	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.thirdRule('R');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.thirdRule('O');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.thirdRule('G');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	// White wire cut then black wire cut

	bomb.firstWire = 'W';
	bomb.lastWire = 'B';

	bomb.thirdRule('W');

	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.thirdRule('B');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.thirdRule('R');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.thirdRule('G');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	// White wire cut then black wire cut

	bomb.firstWire = 'R';
	bomb.lastWire = 'B';

	bomb.thirdRule('W');

	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.thirdRule('B');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.thirdRule('R');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.thirdRule('G');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);
}

TEST(TestBombExplosion, TestExplodeFourthRule) {
	Bomb bomb;

	// Last wire cut was black

	bomb.lastWire = 'B';
	bomb.fourthRule('W');

	bool expectedValue = true;
	bool actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.fourthRule('B');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.fourthRule('R');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.fourthRule('O');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	// Last wire cut was orange

	bomb.lastWire = 'O';

	bomb.fourthRule('W');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.fourthRule('B');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.fourthRule('R');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.fourthRule('O');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

}

TEST(TestBombExplosion, TestExplodeFifthRule) {
	Bomb bomb;

	bomb.fifthRule('W');

	bool expectedValue = true;
	bool actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.fifthRule('B');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.fifthRule('R');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);

	bomb.fifthRule('G');
	actualValue = bomb.exploded;
	EXPECT_EQ(expectedValue, actualValue);
}

// KEEP PLAYING TESTS
TEST(TestKeepPlaying, TestKeepPlayingYes) {
	Bomb bomb;

	ifstream input;
	input.open("test_y.txt", ifstream::in);

	bool expectedValue = true;
	bool actualValue = bomb.keepPlaying(cin);

	EXPECT_EQ(expectedValue, actualValue);
	input.close();
}

TEST(TestKeepPlaying, TestKeepPlayingNo) {
	Bomb bomb;

	ifstream input;
	input.open("test_n.txt", ifstream::in);

	bool expectedValue = false;
	bool actualValue = bomb.keepPlaying(cin);

	EXPECT_EQ(expectedValue, actualValue);
	input.close();
}