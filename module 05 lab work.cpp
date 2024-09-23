
/*

#include <iostream>
#include <string>
#include <memory>


// Интерфейс или абстрактный класс Transport
class Transport {
public:
    virtual void Move() = 0;
    virtual void FuelUp() = 0;
    virtual ~Transport() = default;
};

// Класс Car
class Car : public Transport {
    std::string model;
    int speed;
public:
    Car(const std::string& model, int speed) : model(model), speed(speed) {}
    void Move() override {
        std::cout << "Car " << model << " is moving at speed " << speed << " km/h.\n";
    }
    void FuelUp() override {
        std::cout << "Car " << model << " is fueling up with gasoline.\n";
    }
};

// Класс Motorcycle
class Motorcycle : public Transport {
    std::string model;
    int speed;
public:
    Motorcycle(const std::string& model, int speed) : model(model), speed(speed) {}
    void Move() override {
        std::cout << "Motorcycle " << model << " is moving at speed " << speed << " km/h.\n";
    }
    void FuelUp() override {
        std::cout << "Motorcycle " << model << " is fueling up with gasoline.\n";
    }
};

// Класс Plane
class Plane : public Transport {
    std::string model;
    int speed;
public:
    Plane(const std::string& model, int speed) : model(model), speed(speed) {}
    void Move() override {
        std::cout << "Plane " << model << " is flying at speed " << speed << " km/h.\n";
    }
    void FuelUp() override {
        std::cout << "Plane " << model << " is fueling up with aviation fuel.\n";
    }
};

// Новый тип транспортного средства - IFV
class IFV : public Transport {
    std::string model;
    int speed;
public:
    IFV(const std::string& model, int speed) : model(model), speed(speed) {}
    void Move() override {
        std::cout << "IFV " << model << " is moving at speed " << speed << " km/h through rough terrain.\n";
    }
    void FuelUp() override {
        std::cout << "IFV " << model << " is fueling up with diesel.\n";
    }
};

// Абстрактный класс TransportFactory
class TransportFactory {
public:
    virtual std::unique_ptr<Transport> CreateTransport(const std::string& model, int speed) = 0;
    virtual ~TransportFactory() = default;
};

// Конкретная фабрика для Car
class CarFactory : public TransportFactory {
public:
    std::unique_ptr<Transport> CreateTransport(const std::string& model, int speed) override {
        return std::make_unique<Car>(model, speed);
    }
};

// Конкретная фабрика для Motorcycle
class MotorcycleFactory : public TransportFactory {
public:
    std::unique_ptr<Transport> CreateTransport(const std::string& model, int speed) override {
        return std::make_unique<Motorcycle>(model, speed);
    }
};


class PlaneFactory : public TransportFactory {
public:
    std::unique_ptr<Transport> CreateTransport(const std::string& model, int speed) override {
        return std::make_unique<Plane>(model, speed);
    }
};

// Конкретная фабрика для IFV
class IFVFactory : public TransportFactory {
public:
    std::unique_ptr<Transport> CreateTransport(const std::string& model, int speed) override {
        return std::make_unique<IFV>(model, speed);
    }
};

// Основная функция
int main() {
    std::unique_ptr<TransportFactory> factory;

    std::string choice, model;
    int speed;

    std::cout << "Choose a type of transport (car, motorcycle, plane, ifv): ";
    std::cin >> choice;
    
    std::cout << "Enter model: ";
    std::cin >> model;

    std::cout << "Enter speed: ";
    std::cin >> speed;

    if (choice == "car") {
        factory = std::make_unique<CarFactory>();
    } else if (choice == "motorcycle") {
        factory = std::make_unique<MotorcycleFactory>();
    } else if (choice == "plane") {
        factory = std::make_unique<PlaneFactory>();
    } else if (choice == "ifv") {
        factory = std::make_unique<IFVFactory>();
    } else {
        std::cout << "Unknown transport type.\n";
        return 1;
    }

    auto transport = factory->CreateTransport(model, speed);
    transport->Move();
    transport->FuelUp();

    return 0;
}
*/



#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>


class Transport {
public:
    virtual void Move() = 0;
    virtual void FuelUp() = 0;
    virtual ~Transport() = default;
};


class Car : public Transport {
    std::string model;
    int speed;
public:
    Car(const std::string& model, int speed) : model(model), speed(speed) {}
    void Move() override {
        std::cout << "Car " << model << " is moving at speed " << speed << " km/h.\n";
    }
    void FuelUp() override {
        std::cout << "Car " << model << " is fueling up with gasoline.\n";
    }
};


class Motorcycle : public Transport {
    std::string model;
    int speed;
public:
    Motorcycle(const std::string& model, int speed) : model(model), speed(speed) {}
    void Move() override {
        std::cout << "Motorcycle " << model << " is moving at speed " << speed << " km/h.\n";
    }
    void FuelUp() override {
        std::cout << "Motorcycle " << model << " is fueling up with gasoline.\n";
    }
};


class Plane : public Transport {
    std::string model;
    int speed;
public:
    Plane(const std::string& model, int speed) : model(model), speed(speed) {}
    void Move() override {
        std::cout << "Plane " << model << " is flying at speed " << speed << " km/h.\n";
    }
    void FuelUp() override {
        std::cout << "Plane " << model << " is fueling up with aviation fuel.\n";
    }
};


class IFV : public Transport {
    std::string model;
    int speed;
public:
    IFV(const std::string& model, int speed) : model(model), speed(speed) {}
    void Move() override {
        std::cout << "IFV " << model << " is moving at speed " << speed << " km/h through rough terrain.\n";
    }
    void FuelUp() override {
        std::cout << "IFV " << model << " is fueling up with diesel.\n";
    }
};


class ITransportFactory {
public:
    virtual std::unique_ptr<Transport> CreateTransport(const std::string& model, int speed) = 0;
    virtual ~ITransportFactory() = default;
};


class CarFactory : public ITransportFactory {
public:
    std::unique_ptr<Transport> CreateTransport(const std::string& model, int speed) override {
        return std::make_unique<Car>(model, speed);
    }
};


class MotorcycleFactory : public ITransportFactory {
public:
    std::unique_ptr<Transport> CreateTransport(const std::string& model, int speed) override {
        return std::make_unique<Motorcycle>(model, speed);
    }
};


class PlaneFactory : public ITransportFactory {
public:
    std::unique_ptr<Transport> CreateTransport(const std::string& model, int speed) override {
        return std::make_unique<Plane>(model, speed);
    }
};


class IFVFactory : public ITransportFactory {
public:
    std::unique_ptr<Transport> CreateTransport(const std::string& model, int speed) override {
        return std::make_unique<IFV>(model, speed);
    }
};


class TransportFactoryRegistry {
    std::unordered_map<std::string, std::unique_ptr<ITransportFactory>> factoryMap;
public:
    void RegisterFactory(const std::string& type, std::unique_ptr<ITransportFactory> factory) {
        factoryMap[type] = std::move(factory);
    }

    std::unique_ptr<Transport> CreateTransport(const std::string& type, const std::string& model, int speed) {
        auto it = factoryMap.find(type);
        if (it != factoryMap.end()) {
            return it->second->CreateTransport(model, speed);
        } else {
            std::cerr << "Unknown transport type: " << type << std::endl;
            return nullptr;
        }
    }
};


std::pair<std::string, int> GetTransportInfo() {
    std::string model;
    int speed;

    std::cout << "Enter model: ";
    std::cin >> model;

    std::cout << "Enter speed (km/h): ";
    std::cin >> speed;

    return {model, speed};
}

// Основная функция
int main() {
    TransportFactoryRegistry registry;

    // Регистрация фабрик в реестре
    registry.RegisterFactory("car", std::make_unique<CarFactory>());
    registry.RegisterFactory("motorcycle", std::make_unique<MotorcycleFactory>());
    registry.RegisterFactory("plane", std::make_unique<PlaneFactory>());
    registry.RegisterFactory("ifv", std::make_unique<IFVFactory>());

    std::string choice;

    std::cout << "Choose a type of transport (car, motorcycle, plane, ifv): ";
    std::cin >> choice;

    auto [model, speed] = GetTransportInfo();

    auto transport = registry.CreateTransport(choice, model, speed);
    if (transport) {
        transport->Move();
        transport->FuelUp();
    }

    return 0;
}
