import os

VariantDir('build', 'src')

testEnv = Environment(
	ENV = os.environ,
	CCFLAGS = '-ggdb -Wall',
	CFLAGS = '-fprofile-arcs -ftest-coverage',
	LINKFLAGS = '-fprofile-arcs -ftest-coverage',
	LIBS= ['libgtest', 'libgmock', 'pthread']
)

sources = ['build/add.c']
testSources = ['build/add_test.cc']

testProg = testEnv.Program('a.out', sources + testSources)
testReport = testEnv.Command('test_report.xml', testProg, "./a.out --gtest_output=xml:${TARGET}")
coverageReport = testEnv.Command('coverage.xml', testReport, "gcovr -x -r build -o ${TARGET}")

testEnv.Clean(testProg, 'build')
Default(coverageReport)
