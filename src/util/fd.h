#pragma once
#include <unistd.h>
#include <utility>

class Fd {
public:
    // TODO: a constant kInvalid meaning "no descriptor". Real descriptors are
    // zero or higher, so pick the negative value that open() returns on failure.
    static constexpr int kInvalid=-1;

    // TODO: Fd() owns nothing
    Fd() : fd_(kInvalid) {}
    // TODO: explicit Fd(int fd) takes ownership
    explicit Fd(int fd):fd_(fd){}
    // TODO: ~Fd() closes only if it owns something
    ~Fd(){
        if(fd_!=kInvalid){
            close(fd_);
        }
    }
    // TODO: delete the copy constructor and the copy assignment
    Fd(const Fd&)=delete;
    Fd& operator=(const Fd&)=delete;
    // TODO: move constructor: steal other's number, leave other empty
    Fd(Fd&& other){
        fd_=other.fd_;
        other.fd_=kInvalid;
    }
    // TODO: move assignment: close what you own, then steal,
    //       and guard against assigning an object to itself

    // TODO: int get() const          look at the number, keep ownership
    // TODO: bool valid() const
    // TODO: int release()            give up ownership without closing, return the number
    // TODO: void reset(int fd = kInvalid)   close the current one, adopt the new one
private:
    int fd_;
};