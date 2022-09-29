cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
#add_definitions( "-DPICO_SDK_PATH=\"~/project/pico-sdk\"")

project(my_project)

add_executable( main
    main.c
    BFS.c
    adjList.c
    stackL.c
)
# initialize the Raspberry Pi Pico SDK


# rest of your project