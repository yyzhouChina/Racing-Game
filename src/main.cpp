/*
 * main.cpp
 *
 *  Created on: 21.07.2011
 *      Author: Alex
 */

#include "racingGame.h"
#include "GameStateController.h"
IrrlichtDevice * device;

int initWindow(video::E_DRIVER_TYPE type) {
	device = createDevice(
		type,
		dimension2d<u32>(800, 600),
		16,
		false,
		false,
		false,
		0
	);

	if (!device) {
		printf("Failed to create device");
		return 1;
	}

	device->setWindowCaption(L"Flatout :)");

	return 0;
}

int main() {
	video::E_DRIVER_TYPE type = video::EDT_SOFTWARE;
	if(initWindow(type)) {
		return 1;
	}

	GameStateController controller;

	controller.init(device);

	controller.mainMenu();
	controller.mainLoop();

    device->drop();
	return 0;
}
