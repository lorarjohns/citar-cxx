#ifndef LANGKIT_TAGGER_HMM_TAGGER_PRIVATE
#define LANGKIT_TAGGER_HMM_TAGGER_PRIVATE

#include <cmath>
#include <functional>
#include <string>
#include <vector>

#include <memory>

#include <citar/tagger/wordhandler/WordHandler.hh>
#include <citar/tagger/hmm/Model.hh>
#include <citar/tagger/hmm/LanguageModel.hh>

#include "TrellisEntry.hh"

namespace citar {
namespace tagger {

/**
 * This class implements a Hidden Markov Model (HMM) trigram tagger.
 */
class HMMTaggerPrivate
{
public:
	HMMTaggerPrivate(std::shared_ptr<Model> model, WordHandler const *wordHandler,
		LanguageModel const *languageModel,
		double beamFactor = 1000.0)
	:
		d_model(model), d_wordHandler(wordHandler), d_languageModel(languageModel),
		d_beamFactor(log(beamFactor)) {}

	/**
	 * Tag a sequence of words. A <i>vector</i> of words is expected, the
	 * optimal tag sequence is returned. The sentence should be preceded
	 * by two start markers ended by one end marker. The start markers
	 * should have identical words and tags.
	 */
	std::vector<std::string> tag(std::vector<std::string> sentence)
		const;
private:
	std::shared_ptr<Model> d_model;
	WordHandler const *d_wordHandler;
	LanguageModel const *d_languageModel;
	double d_beamFactor;
};

}
}

#endif // LANGKIT_TAGGER_HMM_TAGGER_PRIVATE
