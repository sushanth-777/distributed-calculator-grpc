// server/calculator_server.cc
#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "../generated/calculator.grpc.pb.h"  // Import generated service interface

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using calculator::Calculator;      // Service
using calculator::Operands;        // Request
using calculator::Result;          // Response

// Implement the Calculator service
class CalculatorServiceImpl final : public Calculator::Service {
    Status Add(ServerContext* context, const Operands* request, Result* reply) override {
        int sum = request->a() + request->b();
        reply->set_value(sum);
        return Status::OK;
    }

    Status Multiply(ServerContext* context, const Operands* request, Result* reply) override {
        int product = request->a() * request->b();
        reply->set_value(product);
        return Status::OK;
    }

    Status Divide(ServerContext* context, const Operands* request, Result* reply) override {
        if (request->b() == 0) {
            return Status(grpc::INVALID_ARGUMENT, "Division by zero");
        }
        int quotient = request->a() / request->b();
        reply->set_value(quotient);
        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");  // Server listens on port 50051
    CalculatorServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);  // Register our service

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "🚀 Server listening on " << server_address << std::endl;

    server->Wait();  // Keep server running
}

int main(int argc, char** argv) {
    RunServer();
    return 0;
}
