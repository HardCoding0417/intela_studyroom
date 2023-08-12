#주제 인터페이스(추상 클래스)
class Subject:
    # 옵저버 등록
    def registerObserver(self, observer):
        pass

    # 옵저버 제거
    def removeObserver(self, observer):
        pass
    
    # 옵저버들에게 알림
    def notifyObservers(self):
        pass

# 주제 인터페이스를 구현할 클래스
class WeatherData(Subject):
    observers = []  

    def registerObserver(self, observer):
        self.observers.append(observer)

    def removeObserver(self, observer):
        self.observers.remove(observer)

    def notifyObservers(self):
        for observer in self.observers:
            #observer.update(self.temperature, self.humidity, self.pressure)
            observer.update()

    def getTemperature(self):
        return self.temperature
    
    def getHumidity(self):
        return self.humidity

    def getPressure(self):
        return self.pressure

    def measurementsChanged(self):
        # display update
        self.notifyObservers()

    # 테스트용 함수
    def setMeasurements(self, temperature, humidity, pressure):
        self.temperature = temperature
        self.humidity = humidity
        self.pressure = pressure
        self.measurementsChanged()

# 옵저버 인터페이스(추상 클래스)
class Observer:
    def __init__(self, weatherData):
        pass
    
    # def update(self, temperature, humidity, pressure):
    #     pass

    def update(self):
        pass

# 디스플레이 인터페이스
class DisplayElement:
    def display(self):
        pass

# 현재 조건 디스플레이
class CurrentConditionsDisplay(Observer, DisplayElement):
    weatherData = WeatherData()

    def __init__(self, weatherData):
        self.weatherData = weatherData
        self.weatherData.registerObserver(self)

    # def update(self, temperature, humidity, pressure):
    #     self.temperature = temperature
    #     self.humidity = humidity
    #     self.display()    
    def update(self):
        self.temperature = self.weatherData.getTemperature()
        self.humidity = self.weatherData.getHumidity()
        self.display()

    def display(self):
        print("현재 상태: 온도 %.1fF, 습도 %.1f%%" %(self.temperature, self.humidity))

# 기상 통계 디스플레이
class StatisticsDisplay(Observer, DisplayElement):
    weatherData = WeatherData()
    maxTemp = 0.0
    minTemp = 200
    tempSum = 0.0
    numReadings = 0

    def __init__(self, weatherData):
        self.weatherData = weatherData
        self.weatherData.registerObserver(self)
    
    # def update(self, temperature, humidity, pressure):
    #     self.tempSum += temperature
    #     self.numReadings+=1

    #     if temperature > self.maxTemp:
    #         self.maxTemp = temperature
    #     if temperature < self.minTemp:
    #         self.minTemp = temperature
        
    #     self.display()

    def update(self):
        temperature = self.weatherData.getTemperature()
        self.tempSum += temperature
        self.numReadings+=1

        if temperature > self.maxTemp:
            self.maxTemp = temperature
        if temperature < self.minTemp:
            self.minTemp = temperature

        self.display()

    def display(self):
        print("평균/최고/최저 온도 = %.1f/%.1f/%.1f"%((self.tempSum/self.numReadings),self.maxTemp,self.minTemp))

# 기상 예보 디스플레이
class ForecastDisplay(Observer, DisplayElement):
    currentPressure = 29.92
    weatherData = WeatherData()

    def __init__(self, weatherData):
        self.weatherData = weatherData
        self.weatherData.registerObserver(self)

    # def update(self, temperature, humidity, pressure):
    #     self.lastPressure = self.currentPressure
    #     self.currentPressure = pressure

    #     self.display()

    def update(self):
        self.lastPressure = self.currentPressure
        self.currentPressure = self.weatherData.getPressure()

        self.display()

    def display(self):
        if self.currentPressure > self.lastPressure:
            print("기상 예보: 날씨가 좋아지고 있습니다!")
        elif self.currentPressure == self.lastPressure:
            print("기상 예보: 지금과 비슷할 것 같습니다.")
        elif self.currentPressure < self.lastPressure:
            print("기상 예보: 쌀살하며 비가 올 것 같습니다.")

# 체감 온도 디스플레이 추가
class HeatIndexDisplay(Observer, DisplayElement):
    heatIndex = 0.0
    weatherData = WeatherData()

    def __init__(self, weatherData):
        self.weatherData = weatherData
        self.weatherData.registerObserver(self)

    # def update(self, temperature, humidity, pressure):
    #     self.heatIndex = self.computeHeatIndex(temperature, humidity)
    #     self.display()

    def update(self):
        t = self.weatherData.getTemperature()
        rh = self.weatherData.getHumidity()
        self.heatIndex = self.computeHeatIndex(t,rh)
        self.display()

    def display(self):
        print("체감 온도: %.5f" %(self.heatIndex))

    def computeHeatIndex(self, t, rh):
        index = (float)((16.923 + (0.185212 * t) + (5.37941 * rh) - (0.100254 * t * rh) +
		(0.00941695 * (t * t)) + (0.00728898 * (rh * rh)) +
		(0.000345372 * (t * t * rh)) - (0.000814971 * (t * rh * rh)) +
		(0.0000102102 * (t * t * rh * rh)) - (0.000038646 * (t * t * t)) + (0.0000291583 *  
		(rh * rh * rh)) + (0.00000142721 * (t * t * t * rh)) +
		(0.000000197483 * (t * rh * rh * rh)) - (0.0000000218429 * (t * t * t * rh * rh)) +     
		0.000000000843296 * (t * t * rh * rh * rh)) -
		(0.0000000000481975 * (t * t * t * rh * rh * rh)))
        return index

# 다른 개발자가 추가한 새로운 디스플레이
class ThirdPartyDisplay(Observer, DisplayElement):
    def update(self):
        pass
    
    def display(self):
        pass

if __name__ == "__main__":
    weatherData = WeatherData()

    # Push 방식 => Subject가 Observer에게 상태를 알리는 방식
    #             ex) notifyObeservers()
    # Pull 방식 => Observer가 Subject로부터 상태를 끌어오는 방식
    #             ex) getter 메소드()
    # 일반적으로 Pull 방식을 옳은 방식이라고 간주함

    currentDisplay = CurrentConditionsDisplay(weatherData)
    statisticsDisplay = StatisticsDisplay(weatherData)
    forcastDisplay = ForecastDisplay(weatherData)
    heatIndexdisplay = HeatIndexDisplay(weatherData)

    weatherData.setMeasurements(80, 65, 30.4)
    weatherData.setMeasurements(82, 70, 29.2)
    weatherData.setMeasurements(78, 90, 29.2)
  