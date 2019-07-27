configure_file (
	"${PROJECT_SOURCE_DIR}/src/configuration.hh.in"
	"${PROJECT_SOURCE_DIR}/src/configuration.hh"
)

add_sources(main.cxx configuration.hh)

add_subdirectory(Graphic)
add_subdirectory(Utility)