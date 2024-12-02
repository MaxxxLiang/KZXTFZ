rm -r build/&&rm -r devel/
cd src/
rm CMakeLists.txt
catkin_init_workspace
cd ..
catkin_make -j8