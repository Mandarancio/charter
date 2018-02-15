project('Charter', 'c',
  version : '2018.01.09',
  license : 'GPL3'
)

PROJECT_NAME = 'charter'
PROJECT_SVG  = 'charter_svg'
PROJECT_TEX  = 'charter_tex'

lib_sources = [
    'src/charter_string.c',
    'src/clist.c',
    'src/parser.c',
    'src/charter.c',
    'src/latex.c',
    'src/svg.c',
    'src/svg_utils.c',
    'src/tinyexpr/tinyexpr.c',
    'src/csv_parser/csvparser.c'
]

bin_sources_svg = [
    'src/main_svg.c'
]

bin_sources_tex = [
    'src/main_tex.c'
]

shared_library(
    PROJECT_NAME,
    sources: lib_sources,
    link_args: '-lm',
    install: true
)

executable(
    PROJECT_SVG,
    sources: [lib_sources, bin_sources_svg],
    link_args: '-lm',
    c_args: '-g',
    install: true
)

executable(
    PROJECT_TEX,
    sources: [lib_sources, bin_sources_tex],
    link_args: '-lm',
    c_args: '-g',
    install: true
)
