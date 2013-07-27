// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include <list>
#include <unordered_set>


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Box2D/Box2D.h>

// TODO: reference additional headers your program requires here
#include "GameObject.h"
#include "GameObjectManager.h"
#include "LevelManager.h"
#include "Game.h"
#include "CollisionInfo.h"
#include "Rigidbody.h"
#include "VisibleGameObject.h"

#include "Character.h"
#include "Ground.h"
#include "Rex.h"
#include "Tile.h"