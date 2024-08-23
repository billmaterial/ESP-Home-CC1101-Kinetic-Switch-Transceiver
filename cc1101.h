// https://github.com/dbuezas/esphome-cc1101
// Modified by bill.material to include more setup options

#ifndef CC1101TRANSCIVER_H
#define CC1101TRANSCIVER_H

#include <ELECHOUSE_CC1101_SRC_DRV.h>

#include "esphome/components/remote_transmitter/remote_transmitter.h"

int CC1101_module_count = 0;
#define get_cc1101(id) (*((CC1101*)id))

class CC1101 : public PollingComponent, public Sensor {
  int _SCK;
  int _MISO;
  int _MOSI;
  int _CSN;
  int _GDO0;  // TX and also RX
  float _bandwidth;
  esphome::remote_transmitter::RemoteTransmitterComponent* _remote_transmitter;
  float _moduleNumber;
  int _last_rssi = 0;

  void setup() {
    pinMode(_GDO0, INPUT);
    ELECHOUSE_cc1101.addSpiPin(_SCK, _MISO, _MOSI, _CSN, _moduleNumber);
    ELECHOUSE_cc1101.setModul(_moduleNumber);
    ELECHOUSE_cc1101.Init();
    ELECHOUSE_cc1101.setRxBW(_bandwidth);
    ELECHOUSE_cc1101.setMHZ(_freq);
//###########################################
    ELECHOUSE_cc1101.setCCMode(0);             // set config for internal transmission mode.
    ELECHOUSE_cc1101.setModulation(2);         // set modulation mode. 0 = 2-FSK, 1 = GFSK, 2 = ASK/OOK, 3 = 4-FSK, 4 = MSK.
    //ELECHOUSE_cc1101.setMHZ(433.92);         // Here you can set your basic frequency. The lib calculates the frequency automatically (default = 433.92).The cc1101 can: 300-348 MHZ, 387-464MHZ and 779-928MHZ. Read More info from datasheet.
    //ELECHOUSE_cc1101.setDeviation(47.60);    // Set the Frequency deviation in kHz. Value from 1.58 to 380.85. Default is 47.60 kHz.
    //ELECHOUSE_cc1101.setChannel(0);          // Set the Channelnumber from 0 to 255. Default is cahnnel 0.
    //ELECHOUSE_cc1101.setChsp(199.95);        // The channel spacing is multiplied by the channel number CHAN and added to the base frequency in kHz. Value from 25.39 to 405.45. Default is 199.95 kHz.
    //ELECHOUSE_cc1101.setRxBW(200);           // Set the Receive Bandwidth in kHz. Value from 58.03 to 812.50. Default is 812.50 kHz.
    ELECHOUSE_cc1101.setDRate(30);             // Set the Data Rate in kBaud. Value from 0.02 to 1621.83. Default is 99.97 kBaud!
    ELECHOUSE_cc1101.setPA(10);                // Set TxPower. The following settings are possible depending on the frequency band.  (-30  -20  -15  -10  -6    0    5    7    10   11   12) Default is max!
    ELECHOUSE_cc1101.setSyncMode(0);           // Combined sync-word qualifier mode. 0 = No preamble/sync. 1 = 16 sync word bits detected. 2 = 16/16 sync word bits detected. 3 = 30/32 sync word bits detected. 4 = No preamble/sync, carrier-sense above threshold. 5 = 15/16 + carrier-sense above threshold. 6 = 16/16 + carrier-sense above threshold. 7 = 30/32 + carrier-sense above threshold.
    //ELECHOUSE_cc1101.setSyncWord(211, 145);  // Set sync word. Must be the same for the transmitter and receiver. (Syncword high, Syncword low)
    //ELECHOUSE_cc1101.setAdrChk(0);           // Controls address check configuration of received packages. 0 = No address check. 1 = Address check, no broadcast. 2 = Address check and 0 (0x00) broadcast. 3 = Address check and 0 (0x00) and 255 (0xFF) broadcast.
    //ELECHOUSE_cc1101.setAddr(0);             // Address used for packet filtration. Optional broadcast addresses are 0 (0x00) and 255 (0xFF).
    //ELECHOUSE_cc1101.setWhiteData(0);        // Turn data whitening on / off. 0 = Whitening off. 1 = Whitening on.
    ELECHOUSE_cc1101.setPktFormat(3);          // Format of RX and TX data. 0 = Normal mode, use FIFOs for RX and TX. 1 = Synchronous serial mode, Data in on GDO0 and data out on either of the GDOx pins. 2 = Random TX mode; sends random data using PN9 generator. Used for test. Works as normal mode, setting 0 (00), in RX. 3 = Asynchronous serial mode, Data in on GDO0 and data out on either of the GDOx pins.
    //ELECHOUSE_cc1101.setLengthConfig(1);     // 0 = Fixed packet length mode. 1 = Variable packet length mode. 2 = Infinite packet length mode. 3 = Reserved
    //ELECHOUSE_cc1101.setPacketLength(0);     // Indicates the packet length when fixed packet length mode is enabled. If variable packet length mode is used, this value indicates the maximum packet length allowed.
    ELECHOUSE_cc1101.setCrc(0);                // 1 = CRC calculation in TX and CRC check in RX enabled. 0 = CRC disabled for TX and RX.
    //ELECHOUSE_cc1101.setCRC_AF(0);           // Enable automatic flush of RX FIFO when CRC is not OK. This requires that only one packet is in the RXIFIFO and that packet length is limited to the RX FIFO size.
    //ELECHOUSE_cc1101.setDcFilterOff(0);      // Disable digital DC blocking filter before demodulator. Only for data rates ≤ 250 kBaud The recommended IF frequency changes when the DC blocking is disabled. 1 = Disable (current optimized). 0 = Enable (better sensitivity).
    //ELECHOUSE_cc1101.setManchester(0);       // Enables Manchester encoding/decoding. 0 = Disable. 1 = Enable.
    //ELECHOUSE_cc1101.setFEC(0);              // Enable Forward Error Correction (FEC) with interleaving for packet payload (Only supported for fixed packet length mode. 0 = Disable. 1 = Enable.
    //ELECHOUSE_cc1101.setPRE(0);              // Sets the minimum number of preamble bytes to be transmitted. Values: 0 : 2, 1 : 3, 2 : 4, 3 : 6, 4 : 8, 5 : 12, 6 : 16, 7 : 24
    //ELECHOUSE_cc1101.setPQT(0);              // Preamble quality estimator threshold. The preamble quality estimator increases an internal counter by one each time a bit is received that is different from the previous bit, and decreases the counter by 8 each time a bit is received that is the same as the last bit. A threshold of 4∙PQT for this counter is used to gate sync word detection. When PQT=0 a sync word is always accepted.
    //ELECHOUSE_cc1101.setAppendStatus(0);     // When enabled, two status bytes will be appended to the payload of the packet. The status bytes contain RSSI and LQI values, as well as CRC OK.
//############################################
    ELECHOUSE_cc1101.SetRx();

  }

  public:
  float _freq;
  CC1101(int SCK, int MISO, int MOSI, int CSN, int GDO0, float bandwidth, float freq,
        esphome::remote_transmitter::RemoteTransmitterComponent* remote_transmitter)
      : PollingComponent(100) {
    _SCK = SCK;
    _MISO = MISO;
    _MOSI = MOSI;
    _CSN = CSN;
    _GDO0 = GDO0;
    _bandwidth = bandwidth;
    _freq = freq;
    _moduleNumber = CC1101_module_count++;
    _remote_transmitter = remote_transmitter;
  }

  void beginTransmission() {
    ELECHOUSE_cc1101.setModul(_moduleNumber);
    ELECHOUSE_cc1101.SetTx();
    pinMode(_GDO0, OUTPUT);
#ifdef USE_ESP32
    _remote_transmitter->setup();
#endif
#ifdef USE_ESP8266
    noInterrupts();
#endif
  }
  void endTransmission() {
    digitalWrite(_GDO0, 0);
    pinMode(_GDO0, INPUT);
#ifdef USE_ESP8266
    interrupts();
#endif
    ELECHOUSE_cc1101.setModul(_moduleNumber);
    ELECHOUSE_cc1101.SetRx();
    ELECHOUSE_cc1101.SetRx();  // yes, twice
  }
  void setBW(float bandwidth) {
    ELECHOUSE_cc1101.setModul(_moduleNumber);
    ELECHOUSE_cc1101.setRxBW(bandwidth);
  }
  void setFreq(float freq) {
    ELECHOUSE_cc1101.setModul(_moduleNumber);
    ELECHOUSE_cc1101.setMHZ(freq);
  }
  bool rssi_on = false;
  void update() override {
    int rssi = 0;
    if (rssi_on) {
      ELECHOUSE_cc1101.setModul(_moduleNumber);
      rssi = ELECHOUSE_cc1101.getRssi();
      if (rssi != _last_rssi) {
        publish_state(rssi);
        _last_rssi = rssi;
      }
    }
  }
};

#endif