// client/calculator_client.cc
#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "../generated/calculator.grpc.pb.h"  // Import generated client stubs

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using calculator::Calculator;   // Service
using calculator::Operands;     // Request
using calculator::Result;       // Response

// Client for Calculator service
class CalculatorClient {
public:
    CalculatorClient(std::shared_ptr<Channel> channel)
        : stub_(Calculator::NewStub(channel)) {}  // Create stub

    int Add(int a, int b) {
        Operands request;
        request.set_a(a);
        request.set_b(b);

        Result reply;

        ClientContext context;

        Status status = stub_->Add(&context, request, &reply);

        if (status.ok()) {
            return reply.value();
        } else {
            std::cerr << "RPC failed: " << status.error_message() << std::endl;
            return -1;
        }
    }

    int Multiply(int a, int b) {
        Operands request;
        request.set_a(a);
        request.set_b(b);

        Result reply;
        ClientContext context;

        Status status = stub_->Multiply(&context, request, &reply);

        if (status.ok()) {
            return reply.value();
        } else {
            std::cerr << "RPC failed: " << status.error_message() << std::endl;
            return -1;
        }
    }

    int Divide(int a, int b) {
        Operands request;
        request.set_a(a);
        request.set_b(b);

        Result reply;
        ClientContext context;

        Status status = stub_->Divide(&context, request, &reply);

        if (status.ok()) {
            return reply.value();
        } else {
            std::cerr << "RPC failed: " << status.error_message() << std::endl;
            return -1;
        }
    }

private:
    std::unique_ptr<Calculator::Stub> stub_;  // Stub to make RPC calls
};

int main(int argc, char** argv) {
    CalculatorClient calculator(grpc::CreateChannel(
        "localhost:50051", grpc::InsecureChannelCredentials()));  // Connect to server

    int a = 10, b = 5;

    int sum = calculator.Add(a, b);
    std::cout << "Add(" << a << ", " << b << ") = " << sum << std::endl;

    int product = calculator.Multiply(a, b);
    std::cout << "Multiply(" << a << ", " << b << ") = " << product << std::endl;

    int quotient = calculator.Divide(a, b);
    std::cout << "Divide(" << a << ", " << b << ") = " << quotient << std::endl;

    return 0;
}
