TEMPLATE = subdirs

SUBDIRS = src/base src/core src/test

core.depends = src/base

test.depends = base core
