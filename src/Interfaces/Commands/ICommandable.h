#ifndef BLOOMFILTER_ICOMMANDABLE_H
#define BLOOMFILTER_ICOMMANDABLE_H

class ICommandable {
    public:
        virtual void execute() = 0;
        virtual ~ICommandable() = default;
};

#endif
