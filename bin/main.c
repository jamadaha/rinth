#include "domain.h"
#include "io.h"
#include "log.h"
#include "problem.h"

int main(int argc, char **argv) {
    LogInit();
    INFO("Reading args");
    if (argc < 3) {
        ERROR("Requires at least 2 args: domain path and problem path.");
        return 1;
    }
    const char *domain_path  = argv[1];
    const char *problem_path = argv[2];
    INFO("Opening domain file");
    File domain_file = FileOpen(domain_path);
    INFO("Parsing domain");
    Domain domain = DomainParse(domain_file.buffer);
    TRACE("Closing domain file");
    FileClose(&domain_file);
    INFO("Opening problem file");
    File problem_file = FileOpen(problem_path);
    INFO("Parsing problem");
    Problem problem = ProblemParse(problem_file.buffer);
    TRACE("Closing problem file");
    FileClose(&problem_file);
    INFO("Parsing finished");
    TRACE("Deleting domain");
    DomainDelete(&domain);
    TRACE("Deleting problem");
    ProblemDelete(&problem);
    return 0;
}
