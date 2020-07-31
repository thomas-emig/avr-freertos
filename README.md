# Experimental AVR ATMega328p Freertos Example

## Compile

- 'mkdir build && cd build/'

- 'cmake ..'

- 'make'

## Upload to Arduino

- To change the default port: 'cmake .. -DAVR_UPLOAD_PORT=/dev/<port>'

- 'make flash-<Projectname>'

## VS Code integration

- Extentions:
  - C/C++ (Microsoft)
  - CMake Integration (Christoph Seitz)
  - Recommended: CMake (twxs)

- Set Build system in Cmake Extention to 'Unix Makefiles'
- Select Project and Target in Status bar
- Build/Flash with F7
