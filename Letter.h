#ifndef LETTER_H_
#define LETTER_H_

class Letter {
public:
	Letter(int index, int length, char const *letter);
	virtual ~Letter();

	int index;
	int length;
	char const *letter;
};

#endif /* LETTER_H_ */
