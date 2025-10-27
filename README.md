# Satellite Removal Simulation

A physics-based orbital mechanics simulation featuring satellite collision detection, debris generation, and user-controlled spacecraft.

## Overview

This simulation models various satellites and spacecraft in Earth orbit, including GPS constellations, the Hubble Space Telescope, Dragon spacecraft, Starlink satellites, and the historic Sputnik. Players control a Dreamchaser spacecraft to interact with these objects in a realistic orbital environment with gravitational physics.

## Features

### Satellite Types
- **GPS Constellation**: 6-satellite constellation with realistic orbital parameters 
- **Hubble Space Telescope**: Space telescope with specialized destruction mechanics 
- **Dragon Spacecraft**: SpaceX crew vehicle with modular design
- **Starlink Satellites**: Modern satellite constellation 
- **Sputnik**: Historic satellite with simple destruction pattern
- **Dreamchaser**: User-controlled spacecraft with thrust and rotation capabilities

### Physics System
- Realistic gravitational simulation using Earth's gravity model 
- 2-step numerical integration for accurate orbital mechanics 
- Collision detection with pixel-to-meter conversion (128,000 meters per pixel)
- Debris fragment generation with realistic velocity kicks 

### Destruction Mechanics
Each satellite type has unique destruction patterns:
- **GPS**: Creates 5 components (center, left, right, 2 fragments)
- **Hubble**: Breaks into 4 specialized parts (telescope, computer, left, right) 
- **Dragon**: 3-part breakdown (center, left, right) plus fragments 
- **Starlink**: 2-part breakdown (body, array)
- **Sputnik**: Simple 4-fragment destruction 

## Controls

- **Down Arrow**: Apply thrust in current direction
- **Left Arrow**: Rotate counterclockwise
- **Right Arrow**: Rotate clockwise
- **Spacebar**: Fire projectiles 

## Technical Architecture

### Core Classes
- `Satellite`: Abstract base class for all space objects 
- `Fragment`: Debris pieces created from destroyed satellites 
- `Projectile`: High-velocity objects with limited lifetime (70 frames)

### Physics Constants
- Earth radius: 6,378,000 meters 
- Earth gravity: 9.80665 m/s²
- Time step: 48.0 time units

## Testing

The project includes comprehensive unit tests for all components:

### Test Categories
- **Satellite Tests**: Individual satellite behavior and destruction 
- **Physics Tests**: Movement, gravity, and collision detection 
- **Component Tests**: Position, velocity, angle, and acceleration classes 

Run tests using the included test framework that inherits from `UnitTest` base class. 

## Building and Running

This is a Visual Studio C++ project configured with OpenGL dependencies.

### Requirements
- Visual Studio with C++ support
- OpenGL libraries (included via NuGet packages)
- Windows environment

### Build Instructions
1. Open `Lab07.vcxproj` in Visual Studio
2. Restore NuGet packages
3. Build and run the project

## Authors

Roger Galan & Jessen Forbush 

## Notes

This simulation demonstrates realistic orbital mechanics with educational value for understanding satellite behavior, collision dynamics, and space debris generation. The physics engine uses accurate gravitational calculations and provides a foundation for studying orbital mechanics concepts. The comprehensive test suite ensures reliability of all physics calculations and entity behaviors.

## Executable Instructions

Build > Configuration Manager > Release 

Build > Build Solution

Open Inno Setup program.

Create new setup script with wizard

point to the exe file in x64/Release

include Release folder just in case

Run setup script.

Add setup compiler.exe to Github Release