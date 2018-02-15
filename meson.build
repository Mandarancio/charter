project('Charter', 'c',
  version : '2018.01.09',
  license : 'GPL3'
)

PROJECT_NAME = 'charter'

lib_sources = [
    'src/clist.c',
    'src/parser.c',
    'src/charter.c',
    'src/renderer.c',
    'src/svg_utils.c',
    'src/tinyexpr/tinyexpr.c',
    'src/csv_parser/csvparser.c'
]

bin_sources = [
    'src/clist.c',
    'src/parser.c',
    'src/charter.c',
    'src/renderer.c',
   	'src/svg_utils.c',
    'src/tinyexpr/tinyexpr.c',
    'src/csv_parser/csvparser.c',
    'src/main.c'
]

shared_library(
    PROJECT_NAME,
    sources: lib_sources,
    link_args: '-lm',
    install: true
)

executable(
    PROJECT_NAME,
    sources: bin_sources,
    link_args: '-lm',
    c_args: '-g',
    install: true
)

.pagebreak { page-break-before: always; } /* page-break-after works, as well */
