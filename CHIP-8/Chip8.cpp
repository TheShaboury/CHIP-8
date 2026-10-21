#include "Chip8.hpp"
#include <cstdint>
#include <fstream>
#include <random>
#include <chrono>
#include <cstring>

const unsigned int START_ADDRESS = 0x200;
const unsigned int FONTSET_START_ADDRESS = 0x50;
const unsigned int FONTSET_SIZE = 80;

// This is how the font looks
/*
	11110000
	10010000
	10010000	---->	0
	10010000
	11110000
*/

uint8_t fontset[FONTSET_SIZE]{
	0xF0, 0x90, 0x90, 0x90, 0xF0,	// 0
	0x20, 0x60, 0x20, 0x20, 0x70,	// 1
	0xF0, 0x10, 0xF0, 0x80, 0xF0,	// 2
	0xF0, 0x10, 0xF0, 0x10, 0xF0,	// 3
	0x90, 0x90, 0xF0, 0x10, 0x10,	// 4
	0xF0, 0x80, 0xF0, 0x10, 0xF0,	// 5
	0xF0, 0x80, 0xF0, 0x90, 0xF0,	// 6
	0xF0, 0x10, 0x20, 0x40, 0x40,	// 7
	0xF0, 0x90, 0xF0, 0x90, 0xF0,	// 8
	0xF0, 0x90, 0xF0, 0x10, 0xF0,	// 9
	0xF0, 0x90, 0xF0, 0x90, 0x90,	// A
	0xE0, 0x90, 0xE0, 0x90, 0xE0,	// B
	0xF0, 0x80, 0x80, 0x80, 0xF0,	// C
	0xE0, 0x90, 0x90, 0x90, 0xE0,	// D
	0xF0, 0x80, 0xF0, 0x80, 0xF0,	// E
	0xF0, 0x80, 0xF0, 0x80, 0x80,	// F
};

Chip8::Chip8() 
	: randGen(std::chrono::system_clock::now().time_since_epoch().count()) {
	
	// Initialize the program counter
	pc = START_ADDRESS;

	// Load the fonts in the memory
	for (unsigned int i = 0; i < FONTSET_SIZE; i++) {
		memory[FONTSET_START_ADDRESS + i] = fontset[i];
	}

	// Initialize the RNG
	randByte = std::uniform_int_distribution<uint8_t>(0, 255U);
}

void Chip8::LoadROM(char const* filename) {

	// Open the file as a stream of binary and move the file pointer to the end
	std::ifstream file(filename, std::ios::binary | std::ios::ate);

	if (file.is_open()) {

		// Get the size of the file
		std::streampos size = file.tellg();
		char* buffer = new char[size];

		// Move the file pointer back to the beginning and read the file data into the buffer
		file.seekg(0, std::ios::beg);
		file.read(buffer, size);
		file.close();

		// Load the ROM content into the memory starting at address 0x200
		for (long i = 0; i < size; i++) {
			memory[START_ADDRESS + i] = buffer[i];
		}

		delete[] buffer;
	}
}

void Chip8::OP_00E0() {
	memset(video, 0, sizeof(video));
}

void OP_00EE() {

}

void OP_1nnn() {

}

void OP_2nnn() {

}

void OP_3xkk() {

}

void OP_4xkk() {

}

void OP_5xy0() {

}

void OP_6xkk() {

}

void OP_7xkk() {

}

void OP_8xy0() {

}

void OP_8xy1() {

}

void OP_8xy2() {

}

void OP_8xy3() {

}

void OP_8xy4() {

}

void OP_8xy5() {

}

void OP_8xy6() {

}

void OP_8xy7() {

}

void OP_8xyE() {

}

void OP_9xy0() {

}

void OP_Annn() {

}

void OP_Bnnn() {

}

void OP_Cxkk() {

}

void OP_Dxyn() {

}

void OP_Ex9E() {

}

void OP_ExA1() {

}

void OP_Fx07() {

}

void OP_Fx0A() {

}

void OP_Fx15() {

}

void OP_Fx18() {

}

void OP_Fx1E() {

}

void OP_Fx29() {

}

void OP_Fx33() {

}

void OP_Fx55() {

}

void OP_Fx65() {

}