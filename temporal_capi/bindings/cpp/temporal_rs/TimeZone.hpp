#ifndef temporal_rs_TimeZone_HPP
#define temporal_rs_TimeZone_HPP

#include "TimeZone.d.hpp"

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <memory>
#include <functional>
#include <optional>
#include <cstdlib>
#include "../diplomat_runtime.hpp"
#include "TemporalError.hpp"


namespace temporal_rs {
namespace capi {
    extern "C" {

    typedef struct temporal_rs_TimeZone_try_from_identifier_str_result {union {temporal_rs::capi::TimeZone* ok; temporal_rs::capi::TemporalError err;}; bool is_ok;} temporal_rs_TimeZone_try_from_identifier_str_result;
    temporal_rs_TimeZone_try_from_identifier_str_result temporal_rs_TimeZone_try_from_identifier_str(diplomat::capi::DiplomatStringView ident);

    typedef struct temporal_rs_TimeZone_try_from_offset_str_result {union {temporal_rs::capi::TimeZone* ok; temporal_rs::capi::TemporalError err;}; bool is_ok;} temporal_rs_TimeZone_try_from_offset_str_result;
    temporal_rs_TimeZone_try_from_offset_str_result temporal_rs_TimeZone_try_from_offset_str(diplomat::capi::DiplomatStringView ident);

    typedef struct temporal_rs_TimeZone_try_from_str_result {union {temporal_rs::capi::TimeZone* ok; temporal_rs::capi::TemporalError err;}; bool is_ok;} temporal_rs_TimeZone_try_from_str_result;
    temporal_rs_TimeZone_try_from_str_result temporal_rs_TimeZone_try_from_str(diplomat::capi::DiplomatStringView ident);

    void temporal_rs_TimeZone_identifier(const temporal_rs::capi::TimeZone* self, diplomat::capi::DiplomatWrite* write);

    temporal_rs::capi::TimeZone* temporal_rs_TimeZone_utc(void);

    temporal_rs::capi::TimeZone* temporal_rs_TimeZone_clone(const temporal_rs::capi::TimeZone* self);

    bool temporal_rs_TimeZone_is_valid(const temporal_rs::capi::TimeZone* self);

    void temporal_rs_TimeZone_destroy(TimeZone* self);

    } // extern "C"
} // namespace capi
} // namespace

inline diplomat::result<std::unique_ptr<temporal_rs::TimeZone>, temporal_rs::TemporalError> temporal_rs::TimeZone::try_from_identifier_str(std::string_view ident) {
  auto result = temporal_rs::capi::temporal_rs_TimeZone_try_from_identifier_str({ident.data(), ident.size()});
  return result.is_ok ? diplomat::result<std::unique_ptr<temporal_rs::TimeZone>, temporal_rs::TemporalError>(diplomat::Ok<std::unique_ptr<temporal_rs::TimeZone>>(std::unique_ptr<temporal_rs::TimeZone>(temporal_rs::TimeZone::FromFFI(result.ok)))) : diplomat::result<std::unique_ptr<temporal_rs::TimeZone>, temporal_rs::TemporalError>(diplomat::Err<temporal_rs::TemporalError>(temporal_rs::TemporalError::FromFFI(result.err)));
}

inline diplomat::result<std::unique_ptr<temporal_rs::TimeZone>, temporal_rs::TemporalError> temporal_rs::TimeZone::try_from_offset_str(std::string_view ident) {
  auto result = temporal_rs::capi::temporal_rs_TimeZone_try_from_offset_str({ident.data(), ident.size()});
  return result.is_ok ? diplomat::result<std::unique_ptr<temporal_rs::TimeZone>, temporal_rs::TemporalError>(diplomat::Ok<std::unique_ptr<temporal_rs::TimeZone>>(std::unique_ptr<temporal_rs::TimeZone>(temporal_rs::TimeZone::FromFFI(result.ok)))) : diplomat::result<std::unique_ptr<temporal_rs::TimeZone>, temporal_rs::TemporalError>(diplomat::Err<temporal_rs::TemporalError>(temporal_rs::TemporalError::FromFFI(result.err)));
}

inline diplomat::result<std::unique_ptr<temporal_rs::TimeZone>, temporal_rs::TemporalError> temporal_rs::TimeZone::try_from_str(std::string_view ident) {
  auto result = temporal_rs::capi::temporal_rs_TimeZone_try_from_str({ident.data(), ident.size()});
  return result.is_ok ? diplomat::result<std::unique_ptr<temporal_rs::TimeZone>, temporal_rs::TemporalError>(diplomat::Ok<std::unique_ptr<temporal_rs::TimeZone>>(std::unique_ptr<temporal_rs::TimeZone>(temporal_rs::TimeZone::FromFFI(result.ok)))) : diplomat::result<std::unique_ptr<temporal_rs::TimeZone>, temporal_rs::TemporalError>(diplomat::Err<temporal_rs::TemporalError>(temporal_rs::TemporalError::FromFFI(result.err)));
}

inline std::string temporal_rs::TimeZone::identifier() const {
  std::string output;
  diplomat::capi::DiplomatWrite write = diplomat::WriteFromString(output);
  temporal_rs::capi::temporal_rs_TimeZone_identifier(this->AsFFI(),
    &write);
  return output;
}
template<typename W>
inline void temporal_rs::TimeZone::identifier_write(W& writeable) const {
  diplomat::capi::DiplomatWrite write = diplomat::WriteTrait<W>::Construct(writeable);
  temporal_rs::capi::temporal_rs_TimeZone_identifier(this->AsFFI(),
    &write);
}

inline std::unique_ptr<temporal_rs::TimeZone> temporal_rs::TimeZone::utc() {
  auto result = temporal_rs::capi::temporal_rs_TimeZone_utc();
  return std::unique_ptr<temporal_rs::TimeZone>(temporal_rs::TimeZone::FromFFI(result));
}

inline std::unique_ptr<temporal_rs::TimeZone> temporal_rs::TimeZone::clone() const {
  auto result = temporal_rs::capi::temporal_rs_TimeZone_clone(this->AsFFI());
  return std::unique_ptr<temporal_rs::TimeZone>(temporal_rs::TimeZone::FromFFI(result));
}

inline bool temporal_rs::TimeZone::is_valid() const {
  auto result = temporal_rs::capi::temporal_rs_TimeZone_is_valid(this->AsFFI());
  return result;
}

inline const temporal_rs::capi::TimeZone* temporal_rs::TimeZone::AsFFI() const {
  return reinterpret_cast<const temporal_rs::capi::TimeZone*>(this);
}

inline temporal_rs::capi::TimeZone* temporal_rs::TimeZone::AsFFI() {
  return reinterpret_cast<temporal_rs::capi::TimeZone*>(this);
}

inline const temporal_rs::TimeZone* temporal_rs::TimeZone::FromFFI(const temporal_rs::capi::TimeZone* ptr) {
  return reinterpret_cast<const temporal_rs::TimeZone*>(ptr);
}

inline temporal_rs::TimeZone* temporal_rs::TimeZone::FromFFI(temporal_rs::capi::TimeZone* ptr) {
  return reinterpret_cast<temporal_rs::TimeZone*>(ptr);
}

inline void temporal_rs::TimeZone::operator delete(void* ptr) {
  temporal_rs::capi::temporal_rs_TimeZone_destroy(reinterpret_cast<temporal_rs::capi::TimeZone*>(ptr));
}


#endif // temporal_rs_TimeZone_HPP
