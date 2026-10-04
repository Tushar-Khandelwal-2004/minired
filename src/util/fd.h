#pragma once
#include <unistd.h>
#include <utility>
#include <iostream>

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
    // ~Fd(){
    //     if(fd_!=kInvalid){
    //         close(fd_);
    //     }
    // }
    ~Fd() {
    if (fd_ != kInvalid) {
        std::cout << "Fd destructor closing " << fd_ << '\n';
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
    Fd& operator=(Fd&& other)
    {
    // self assignment check
        if(this==&other){
            return *this;
        }
    // close current descriptor if valid
        if(this->fd_!=kInvalid){
            close(this->fd_);
        }
    // steal descriptor
        this->fd_=other.fd_;
    // invalidate other
        other.fd_=kInvalid;
    // return myself
    return *this;
    }
    // TODO: int get() const          look at the number, keep ownership
        int get() const
        {
            return this->fd_;
        }
    // TODO: bool valid() const
        bool valid()const
        {
            return this->fd_!=kInvalid;
        }
    // TODO: int release()            give up ownership without closing, return the number
        int release(){
            int temp = fd_;
            fd_ = kInvalid;
            return temp;
        }
    // TODO: void reset(int fd = kInvalid)   close the current one, adopt the new one
    void reset(int fd=kInvalid){
        if(fd_==fd){
            return;
        }
        if(fd_==kInvalid){
            return;
        }
        close(fd_);
        fd_=fd;
    }
private:
    int fd_;
};