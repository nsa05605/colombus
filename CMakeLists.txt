cmake_minimum_required(VERSION 3.2)

project(colombus)

IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release)
ENDIF()

# src 디렉토리의 모든 cpp 파일을 변수에 저장
file(GLOB SOURCE_FILES "src/*.cpp")

# 소스 파일 목록을 반복하며 add_executable 실행
foreach(SOURCE_FILE ${SOURCE_FILES})
    # 파일 이름에서 확장자를 제거하여 타겟 이름 생성
    get_filename_component(TARGET_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${TARGET_NAME} ${SOURCE_FILE})
endforeach()