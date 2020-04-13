#include "driver.h"

void Driver::Run(std::istream &input_stream, std::ostream &output_stream)
    : input_stream_(input_stream), output_stream_(output_stream) {}