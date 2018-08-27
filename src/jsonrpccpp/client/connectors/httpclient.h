/*************************************************************************
 * libjson-rpc-cpp
 *************************************************************************
 * @file    httpclient.h
 * @date    02.01.2013
 * @author  Peter Spiess-Knafl <dev@spiessknafl.at>
 * @license See attached LICENSE.txt
 ************************************************************************/

#ifndef JSONRPC_CPP_HTTPCLIENT_H_
#define JSONRPC_CPP_HTTPCLIENT_H_

#include "../iclientconnector.h"
#include <curl/curl.h>
#include <jsonrpccpp/common/exception.h>
#include <map>

namespace jsonrpc {
class HttpClient : public IClientConnector {
public:
  HttpClient(const std::string &url);
  virtual ~HttpClient();
  virtual void SendRPCMessage(const std::string &message, std::string &result);

  void SetUrl(const std::string &url);
  void SetSSLKey(const std::string &sslkey, const std::string &sslkeypwd = "",
    const std::string &sslkey_type = "PEM");
  void SetSSLCert(const std::string &certpath, const std::string &sslcert_type = "PEM");
  void SetSSLTrust(const std::string &ssltrust);
  void SetVerifyHost(bool verifyhost);
  void SetVerifyPeer(bool verifypeer);
  void SetTimeout(long timeout);

  void AddHeader(const std::string &attr, const std::string &val);
  void RemoveHeader(const std::string &attr);

private:
  std::map<std::string, std::string> headers;
  std::string url, sslcert, sslcert_type, sslkey, sslkeypwd, sslkey_type, ssltrust;
  bool verifyhost, verifypeer;

  /**
   * @brief timeout for http request in milliseconds
   */
  long timeout;
  CURL *curl;
};

} /* namespace jsonrpc */
#endif /* JSONRPC_CPP_HTTPCLIENT_H_ */
